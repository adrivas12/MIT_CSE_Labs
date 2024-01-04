#Consider the tuple(1,3,5,7,9,2,4,6,8,10). Write a program to print half its values in one line and
#the other half in the next line.

tp = (1, 3, 5, 7, 9, 2, 4, 6, 8, 10)
tp1 = tp[5:]
tp2 = tp[:5]
print(tp1)
print(tp2)