# looping and conditional branches in python

#Eg1
# num = float(input('Enter a number: '))
# if num>0:
# 	print('pos number')
# elif num==0:
# 	print('zero')
# else:
# 	print('Neg number')

#Eg2
# x = float(input('Enter a number: '))
# if x<10: 
# 	print('smaller')
# elif x>20:
# 	print('bigger')
# print('Finished')

#Eg3
# x = 5 
# print('before 5')
# if x == 5:
# 	print('this is 5')
# 	print('still 5')
# print('After 5')
# print('Before 6')
# if x==6:
# 	print('this is 6')
# print('After 6')

#Eg4
# x=float(input('Enter a number:'))
# if x<20:
# 	print('Below 20')
# elif x<10:
# 	print('Below 10')
# else:
# 	print('something else')

#Eg5: nested decisions
# x = 42
# if x>1:
# 	print('above one')
# 	if x<100:
# 		print('less than 100')
# print('all done')

#Eg6: Ternary operator
# age = 15
# b = ('kid' if age<18 else 'adult')
# print(b)