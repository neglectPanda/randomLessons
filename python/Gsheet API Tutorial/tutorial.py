import gspread 
from google.oauth2.service_account import Credentials

# Scopes of the functions you can do
scopes = [
    "https://www.googleapis.com/auth/spreadsheets"
]

# Connect credentials.json to python
creds = Credentials.from_service_account_file("credentials.json", scopes=scopes)

# Authorize ourself
client = gspread.authorize(creds)

# Access ID
sheet_id = "1N8rgBTHUlCMF_bIkoI6yhzIdN6NOxJf4DwrhhypTEds"

# Open spreadsheet
workbook = client.open_by_key(sheet_id)

# Test
# values_list = sheet.sheet1.row_values(1)
# print(values_list) -- Output: the 'test value' string we placed in sheets initially

# To see a sheet title
# sheets = map(lambda x: x.title, workbook.worksheets())

# Update a sheet title
sheet = workbook.worksheet("Hello") # Since we activated the code
# sheet.update_title("Hello")

# Update a cell
sheet.update_cell(1, 1, "CHANGED") # (row, col)

# Get a value of a cell
value = sheet.cell(1, 1).value

# Find a cell by its text
cell = sheet.find("Yes")
# print(cell.row, cell.col)

# Format
sheet.format("A1:B1", {"textFormat":{"bold":True}})