import pandas as pd

# data = pd.read_csv("/myProgProjs/randomLearnings/python/Pandas/customers-100.csv", index_col = 0) # index_col = 0 removes the weird column thing

# .index - the first index row has a editable info column 

print(pd.__version__)

# Column Access []
# varName[['col_name']]

# Row Access[]
# varName[start : end]

# Column Access loc
# varName[['col_name']]

# Row Access loc
# varName.loc[['row_name']]

# Row & Column Access
# varName.loc[['row_name'], ['col_name']]

# Row Acces iloc -- indexing or a list when using
# varName.iloc[1]

#first_name = data.loc[:, 'first_name']
#print(first_name) 

####################################################################################
#LOOPING lessons

#.iterrows 

# for lab, row in brics.iterrows() :
#     brics.loc[lab, "name_length"] = len(row["country"])
#this is when u use a for loop and add a new column to ur pd df

#######################################################################################
# Data manipulation with pandas
# .head() - returns the first few rows of the data frame
# .info() - shows information on each of the columns (data type and number of missing values)
# .describe() - calculates few summary statistics for each column
# 
#
# Parts of a data frame
# .values - returns a 2d numpy array of values
# .columns - returns index of columns (the column names)
# .index - returns index for the rows

#############################################################################################
# Sorting and subsetting
# .sort_values("column_name")
# subsetting is just var_name["column_name"]
#       Example:
#           dogs[dogs["height"] > 50] -- filters out all info of dogs with a height greater than 50
#           for multiple conditions and is this '&'
# .isin()
#       Example:
#           dogs["color"].isin(["Black", "Brown"])


#############################################################################################
#                                   Summary Statistics
# .mean()
# .median()
# .mode()
# .min()
# .max()
# .var()
# .std()
# .sum()
# .quantile()
# .cummax()
# .cummin()
# .cumsum()
# .cumprod()

##############################################################################################
#                                           Counting

# .drop_duplicates(subset="column_name") -- gets values of specified column that are unique and dont have duplicates
# .value_counts(sort=True) -- counts a column's value (example labrador 2, chow chow 1)
# .value_counts(normalize=True) -- counts a proportion of values
# .agg

##############################################################################################
#                               Grouped summary statistics

# .groupby("column_name")["another_col"]

##############################################################################################
#                                         Pivot Tables

# .pivot_table(values="col_values_target", index="another_col")
#   example:
#       dogs.pivot_table(values="weight_kg", index="color") -- based on dog color, we get their weights mean
#       dogs.pivot_table(values="weight_kg", index="color", aggfunc=np.median)
#       dogs.pivot_table(values="weight_kg", index="color", columns="breed", fill_value=0, margins=True)
#           for the extra column we want it with
#           to replace NaN with 0
#           gets the mean for each row and then at the last column and every column

##############################################################################################
#                                   Explicit indexes   
#    
# .set_index("col_name ") -- removes the 0, 1, 2, 3....
# .reset_index() -- undo the one above
#       (drop=True) removes the first column
