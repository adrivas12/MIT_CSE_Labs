#Write a python class to implement pow(x, n)

class py_solution:
    def pow(self, x, n):
        power = 1
        for i in range(n): 
            power *= x
            n=n-1
        return power

print(py_solution().pow(2, 5))

'''
Alternate optimised solution 
class py_solution:
    def pow(self, x, n):
        # Base case: x^0 = 1
        if n == 0:
            return 1
        # Recursive case: x^n = x^(n/2) * x^(n/2) if n is even
        # x^n = x * x^(n/2) * x^(n/2) if n is odd
        half = self.pow(x, n // 2)
        if n % 2 == 0:
            return half * half
        else:
            return x * half * half

print(py_solution().pow(2, 5))
'''