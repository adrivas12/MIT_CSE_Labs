import numpy as np 
import random

# Array Creation
# A = np.array([2, 5, 10])
# print(A.dtype)

# B = np.array([2.4, 10.6, 5.2])
# print(B.dtype)

# #2. Creating sequence of sequence will create 2-dimensional array.
# A=np.array([(3,4,5),(12,6,1)])
# Z=np.zeros((2,4))
# print("A: ", A)
# print("Z: ", Z)

# # 3. To create  a sequence of data
# S = np.arange(10, 30, 5)
# print(S)
# B= np.arange(0, 2, 0.3)
# print(B)

# S1 = np.linspace (0, 2, 9)
# print(S1)
# S2= random.randrange(25,50,2)
# print(S2)

# 2D Matrix 
# a = np.arange(15).reshape(3, 5)
# print(a)

# 3D Matrix 
# c = np.arange(24).reshape(2, 3, 4)
# print(c)
# print("Shape: ", c.shape)
# print(c[1, :, :])

# Array Operations 
# a= np.array([20, 30, 40, 50])
# b = np.arange(4)
# print("A: ", a)
# print("B: ", b)
# print("B**2: ", b**2)
# print("10*np.sin(a): ", 10*np.sin(a))
# print("a<35: ", a<35)
# c = a-b
# print(c)

# Matrix Operations 
# A = np.array([[1, 1], [0, 1]])
# B = np.array([[2, 0], [3, 4]])
# print("A: ", A)
# print("B: ", B)
# print("A*B: ", A*B)
# print("A.dot(B): ", A.dot(B))
# print("np.dot(A, B): ", np.dot(A, B))
# C= np.arange(12).reshape(3, 4)
# print("\n\nC: ", C)
# print("C sum 1: ",C.sum(axis = 0))
# print("C sum 2: ", C.sum(axis = 1))

# Indexing, Slicing and Iterating Array
# a = np.arange(10)**3
# print("a: ", a)
# print("a[2:5]: ", a[2: 5])
# print("a[0: 6: 2]: ", a[0: 6: 2])

# b = np.array([[ 0, 1, 2, 3],
# [10, 11, 12, 13],
# [20, 21, 22, 23],
# [30, 31, 32, 33],
# [40, 41, 42, 43]])

# print("\n\nb[2, 3]: ", b[2,3])
# print("b[0:5, 1]: ", b[0: 5,1])
# print("b[-1,:]: ", b[-1, :])
# print("b[:, -1]: ", b[:, -1])
# for row in b: 
# 	print(row)
# for element in b.flat: 
# 	print(element)


# # Changing shape 
# b = np.array([[ 0, 1, 2, 3],
# [10, 11, 12, 13],
# [20, 21, 22, 23],
# [30, 31, 32, 33],
# [40, 41, 42, 43]])

# print(b.ravel())
# B1 = b.reshape(4, 5)
# print(B1)

# Stacking together different arrays 
# A1 = np.array([(3, 4, 5), (12, 6, 1)])
# print("A1: \n",A1)
# A2=np.array([(1,2,6),(-4,3,8)])
# print("A2: \n", A2)

# D1=np.vstack((A1,A2))
# print("D1: \n", D1)

# D2=np.hstack((A1,A2))
# print("D2: \n", D2)

# Stacking 1D array into 2D array (column wise)
# a = np.array([4., 2.])
# b = np.array([3., 8.])
# print(np.column_stack((a, b)))
# print(np.hstack((a, b)))

# Indexing with array of indices 
# a = np.arange(12)**2
# i = np.array([1, 1, 3, 8, 5])
# print(a[i])

# j= np.array([[3, 4], [9, 7]])
# print(a[j])

# Usage of for-loop(Mapping by value)
# a=np.array([(3,2,9),(1,6,7)])
# s1=0
# for row in a:
# 	for col in row:
# 		s1+=col-
# print(s1)

# Usage of for-loop (Mapping by index)
# a = np.array([(3, 2, 9), (1, 6, 7)])
# s=0
# for i in range(a.shape[0]): 
# 	for j in range(a.shape[1]): 
# 		s+=a[i, j]
# print(s)