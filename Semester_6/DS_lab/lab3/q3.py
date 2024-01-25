# 3. Operations on Arrays (use numpy wherever required):
# a) Create array from list with type float
# b) Create array from tuple
# c) Creating a 3X4 array with all zeros
# d) Create a sequence of integers from 0 to 20 with steps of 5
# e) Reshape 3X4 array to 2X2X3 array
# f) Find maximum and minimum element of array, Row wise max and min, column wise max
# and min and sum of elements. (Use functions max(), min(), sum())

import numpy as np

list = [1, 2, 3 ,4 ,5, 6]
A = np.array(list, dtype=float)
print("A: \n", A)

tuple = (7, 8, 9, 10, 11, 12)
B = np.array(tuple)
print("B: \n", B)

C = np.zeros((3, 4))
print("C: \n", C)

D = np.arange(0, 21, 5)
print("D: \n", D)

E = C.reshape(2, 2, 3)
print("E: \n", E)

F = np.arange(12).reshape(3, 4)
print("F: \n", F)
F_max = np.max(F)
print("Max number in Matrix: ", F_max)
F_min = np.min(F)
print("Min number in Matrix: ", F_min)
F_max_row = np.max(F, axis = 1)
print("Max number in rows: ", F_max_row)
F_min_row = np.min(F, axis = 1)
print("Min number in rows: ", F_min_row) 
F_max_col = np.max(F, axis = 0)
print("Max number in cols: ", F_max_col)
F_min_col = np.min(F, axis = 0)
print("Min number in cols: ", F_min_col) 
F_sum = np.sum(F)
print("Sum of all elements: ", F_sum)