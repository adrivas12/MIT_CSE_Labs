# Write a python class which has two methods get_String and print_String 
#get_String accept a string from the user and print_String print the string in 
#upper case

class py_solution:
    def get_String(self):
        string = str(input("Enter string: "))
        return string

    def print_String(self, string):
        return string.upper()
        

print(py_solution().get_String())
print(py_solution().print_String(py_solution().get_String()))

