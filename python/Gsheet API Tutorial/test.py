import gspread
from google.oauth2.service_account import Credentials
import json

# Accessing json data
with open('data.json', 'r') as file:
    data = json.load(file)

# Getting names, height, weight from the json file
names = [item["name"] for item in data if "name" in item]
height_in_m = [item["height_in_m"] for item in data if "height_in_m" in item]
weight_in_kg = [item["weight_in_kg"] for item in data if "weight_in_kg" in item]

scopes = ["https://www.googleapis.com/auth/spreadsheets"]
creds = Credentials.from_service_account_file("credentials.json", scopes=scopes)
client = gspread.authorize(creds)

sheet_id = "1N8rgBTHUlCMF_bIkoI6yhzIdN6NOxJf4DwrhhypTEds"
workbook = client.open_by_key(sheet_id)

worksheet_list = map(lambda x: x.title, workbook.worksheets())
new_worksheet_name = "Test"

# add worksheet
if new_worksheet_name in worksheet_list:
    sheet = workbook.worksheet(new_worksheet_name)
else:
    sheet = workbook.add_worksheet(new_worksheet_name, rows=10, cols=10)

sheet.clear()

# heading values
headings = ["Name", "Height in m", "Weight in kg", "Calculated BMI"]

# Putting the headings in sheets
sheet.update("A1:D1", [headings])
sheet.format("A1:D1", {
    "textFormat": {"bold": True},
    "horizontalAlignment": "CENTER"
})

# list containing name, height, weight
values = list(zip(names, height_in_m, weight_in_kg))

# names, height, weight from json to sheets
if values:
    sheet.update(f"A2:C{len(values) + 1}", values)

for i in range(2, len(values) + 2):
    bmi_formula = f"=IF(B{i} > 0, C{i}/(B{i} * B{i}), \"N/A\")"
    sheet.update_cell(i, 4, bmi_formula)