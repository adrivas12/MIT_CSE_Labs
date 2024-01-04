#Q9) Write a python program to count positive and negative numbers in a list

list =[11, -21, -1, 45, 66, -93]
countpos = countneg = 0
for i in range(len(list)):
	if list[i]<0:
		countneg=countneg+1
	elif list[i]>0:
		countpos=countpos+1
print(countpos)
print(countneg)