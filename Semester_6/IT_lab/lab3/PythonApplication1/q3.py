#Write a python program to implement binary search with recursion

def Binary_Search(arr, low, high, x): 
	if high>=low: 
		mid=(high+low)//2
		if arr[mid]==x: 
			return mid
		elif arr[mid]>x: 
			return Binary_Search(arr, low, mid-1, x)
		else: 
			return Binary_Search(arr, mid+1, high, x)
	else: 
		return -1

arr=[4, 5, 6, 2, 6, 10]
x = 10
res=Binary_Search(arr, 0, len(arr)-1, x)
if res!=-1: 
	print("Element present at: ", str(res))
else: 
	print("Element not present in array")
