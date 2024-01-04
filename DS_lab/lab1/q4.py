#largest amoung three numbers 
x = [12, 15, 3]
if x[0]>x[1] and x[0]>x[2]:
	print(x[0])
elif x[1]>x[2] and x[1]>x[0]:
	print(x[1])
else:
	print(x[2])
