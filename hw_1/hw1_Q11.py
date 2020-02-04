# Bryan Thiha

# Given list a =[2,8,10,15,17,7]  write a Python code that goes through  the list, checks to see if the integer is odd 
# and if TRUE it prints out the summation of that integer and maximum of the list a. 

a = [2,8,10,15,17,7]

for i in range(len(a)):
	if a[i] % 2 != 0:			# Checks to see if integer is odd
		print (a[i] + max(a))