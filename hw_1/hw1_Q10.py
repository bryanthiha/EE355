# Bryan Thiha

# Think of 2 different scenarios that changing one single indentation would produce two different results in a single python code. 

# one scenario for indentation, both indentations are in this file to make it easier to read
# Plz comment out the other to test one out

a = [5, 2, 6, 13, 1]

for i in range(len(a)):
	if a[i] > 2:
		print(a[i])
		print(i)

###################################

a = [5, 2, 6, 13, 1]

for i in range(len(a)):
	if a[i] > 2:
		print(a[i])
	print(i)