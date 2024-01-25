# 1. Write a program to find the factors of a given number (get input from user) using for loop 

num = int(input("Enter a number: "))
print("Factors of ", num)
for i in range(1, num+1): 
	if num%i ==0: 
		print(i)