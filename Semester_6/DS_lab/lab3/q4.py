# 4. Write a program to transpose a given matrix 

import numpy as np 

B = np.arange(12).reshape(3, 4)
print("Array B: ", B)
B_T = B.transpose()
print("Array B transpose: ", B_T)