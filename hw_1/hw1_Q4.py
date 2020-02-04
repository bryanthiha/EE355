# Bryan Thiha

#Given the list a = [20,44,30,6] write a Python for loop that prints out elements of list in reverse. 
#Don't use reverse function.  


a = [20, 44, 30, 6]

for i in range(len(a), 0, -1):		#decrements from last index to first index
	print(a[i-1])