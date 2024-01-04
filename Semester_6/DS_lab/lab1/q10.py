#Q10) Write a python program to remove all even elements from a list

list =[11, -21, -1, 45, 66, -93]
for i in range(len(list)):
	if list[i]%2 == 0:
		list[i] = 0
print(list)