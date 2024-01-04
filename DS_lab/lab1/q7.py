#Consider the tuple (12, 7, 38, 56, 78 ). Write a program to print another tuple whose values are
#even number in the given tuple.

tp = (12, 7, 38, 56, 78)
for i in range(len(tp)):
	if(tp[i]%2 == 0):
		print(tp[i])