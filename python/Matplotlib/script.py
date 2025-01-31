import matplotlib.pyplot as plt
import numpy as np

height = [1.58, 1.65, 1.45, 1.55, 1.75]
weight = [60.32, 58.42, 49.27, 51.23, 65.34]

np_height = np.array(height)
np_weight = np.array(weight)

# .plot is a line graph
# .scatter is ascatter graph

plt.scatter(np_height, np_weight)
plt.xlabel("Height")
plt.ylabel("Weight")
plt.title("Height and weight")


plt.show()