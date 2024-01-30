#Write a python class to get all possible unique subsets from a distinct set of integers
#Input: [4, 5, 6] Output: [[], [6], [5], [5, 6], [4], [4, 6], [4, 5], [4, 5, 6]]

class py_solution:
    def sub_sets(self, set):
        return self.subsetsRecur([], sorted(set))
    
    def subsetsRecur(self, current, set):
        if set:
            return self.subsetsRecur(current, set[1:]) + self.subsetsRecur(current + [set[0]], set[1:])
        return [current]

print(py_solution().sub_sets([4,5,6]))
