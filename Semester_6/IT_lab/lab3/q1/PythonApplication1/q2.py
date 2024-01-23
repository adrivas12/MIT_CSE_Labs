#Write a python program to reverse a content a file and store it in another file

file=open(r"C:\Users\IT\Desktop\210905244\IT_lab\lab3\q1\output1.txt", "w")
with open(r"C:\Users\IT\Desktop\210905244\IT_lab\lab3\q1\file.txt.txt", "r") as myfile: 
	data=myfile.read()

data_1 = data[::-1]
file.write(data_1)
file.close()
