# usage of For-loop

#Eg1
# for val in [5, 4, 3, 2, 1]:
# 	print(val)
# print('done')

#Eg2)
# stud = ['ram', 'Vijay','Nithya', 'Anu', 'Ramesh', 'suja']
# for k in stud: 
# 	print('Hello ', k)
# print('done')

#Eg3
# for i in range(5):
# 	print(i)
# 	if i<2:
# 		print('Bigger than 2')
# 	print('done with i', i)

#Eg4 factors of a number
# x = int(input('Enter a number:'))
# for i in range(1, x+1):
# 	if x%i == 0:
# 		print(i)

#Eg5 largest number in an array
# from math import *
# x = [9, 41, 12, 3, 74, 15]
# largest= -inf
# for i in x: 
# 	if i>largest:
# 		largest = i
# print(largest)

#Eg6 smallest number in an array
# from math import *
# x= [9, 41, 12, 3, 74, 15]
# smallest = inf 
# for i in x: 
# 	if i<smallest:
# 		smallest = i 
# print(smallest)

#Eg7 Calculate the count, sum and average of numerical array
# x = [9, 41, 12, 3, 74, 15]
# count = sum = avg = 0

# for i in x: 
# 	count = count +1
# 	sum = sum + i
# avg = sum/count
# print(count)
# print(sum)
# print(avg)

#Eg8 Filtering in a loop(print all numbers > 20)
# x = [9, 41, 12, 3, 74, 15]
# for i in x: 
# 	if i>20: 
# 		print (i)

#Eg9
# x = [9, 41, 12, 3, 74, 15]
# res = []
# for i in x: 
# 	if i>20: 
# 		res.append(i)

#Eg10
# import numpy as np
# y = np.zeros(len(x))
# for i in range(len(x)):
# 	if x[i] > 20:
# 		y[i] = x[i]
# print(y)