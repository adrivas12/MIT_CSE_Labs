#Write a Python program to print negative Numbers in a List using for loop. Eg. [11, −21, 0, 45,
#66, −93].

list = [11, -21, 0, 45, 66, -93]
for i in range(len(list)):
	if list[i]<0:
		print(list[i])