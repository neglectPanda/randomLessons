import numpy as np

# random numbers say height and weight
# 500 rows

# Generate random data
height = np.round(np.random.normal(1.75, 0.20, 500), 2) 
weight = np.round(np.random.normal(60.32, 15, 500), 2)

np_city = np.column_stack((height, weight))

# Mean, Median, and Standard deviation
mean_height = np.round(np.mean(height), 2)
mean_weight = np.round(np.mean(weight), 2)
median_height = np.round(np.median(height), 2)
median_weight = np.round(np.median(weight), 2)
std_height = np.round(np.std(height), 2)
std_weight = np.round(np.std(weight), 2)

# Correlation Coefficient between the two variables
corr_coef = np.round(np.corrcoef(height, weight)[0, 1], 2) # [0, 1] adds scalar value

# Variance
var_height = np.round(np.var(height), 2)
var_weight = np.round(np.var(weight), 2)

# Range (difference between max and min)
range_height = np.round(np.ptp(height), 2)
range_weight = np.round(np.ptp(weight), 2)

# Store in dictionary
city_info = {
    "Mean Height" : mean_height,
    "Mean Weight" : mean_weight,
    "Median Height" : median_height,
    "Median Weight" : median_weight,
    "Standard Deviation Height" : std_height,
    "Standard Deviation Weight" : std_weight,
    "Variance of Weight" : var_weight,
    "Variance of Height" : var_height,
    "Range of Weight" : range_weight,
    "Range of Height" : range_height,
    "Correlation Coefficient" : corr_coef
}

# .items is used for looping through a dicitionary
for key, value in city_info.items():
    print(f"{key}: {value}")

#############################################################3
# from the lesson LOOPINGS

#np.nditer(np_array) iterates over numpy arrays