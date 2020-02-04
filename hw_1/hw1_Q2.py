# Bryan Thiha

# Given list a=[6,14,19,24,6,7,6,24,1,3], write a Python code  that for each unique element, prints out that element. 
# Format of output is yours to choose.

a = [6,14,19,24,6,7,6,24,1,3]

a.sort()										#organizing them in ascending order to check

for i in range(len(a)):						
	if a[i-1] != a[i] and a[i] != a[i+1]:		#checking if left and right is same number
		print(a[i])
	