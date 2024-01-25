# 2. Find the sum of columns and rows using axis 

import numpy as np

A = np.array([[1, 2, 3, 4], 
	[5, 6, 7, 8]])
print("Sum of each column: ", A.sum(axis=0))
print("Sum of each Row: ", A.sum(axis=1))