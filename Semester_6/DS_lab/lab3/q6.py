# 6. Write a program to find element wise product between two matrices 

import numpy as np
A = np.arange(12).reshape(3, 4)
B = np.arange(5, 17).reshape(3, 4)
print("A: \n", A)
print("B: \n", B)
print("A*B= \n", np.multiply(A, B))