#Write a python class to find a pair of elements(indices of two numbers) from 
#a given array whose sum equals a specific target number. 
#input number: [10, 20, 10, 40, 50, 60, 70] target = 50 
#Output: 3, 4 or 1, 4
'''
class py_solution:
    def sets(self, target, set):
        return self.subTarget(target,set)
    
    def subTarget(self, target, set):
        for i in range(len(set)): 
            for j in range(len(set)): 
                if set[i]+set[j]==target: 
                    return i+1, j+1
        return 0
print(py_solution().sets(12,[5, 4, 6, 89, 8, 9] ))
'''
class py_solution:
    def sets(self, target, set):
        dic = {}
        for i in range(len(set)):
            complement = target - set[i]
            if complement in dic:
                return dic[complement] + 1, i + 1
            dic[set[i]] = i
        return 0

print(py_solution().sets(50, [10, 20, 10, 40, 50, 60, 70]))
