# Bryan Thiha

# other scenario for indentation, both indentations are in this file to make it easier to read
# Plz comment out the other to test one out

x = int(input("Input Integer -> ")) 

if x > 5:
	x += 6
	if x < 15:
		print(x)
		if x > 13:
			print("arrived")
	else:
		x = x - 5
		print(x)

###########################################

x = int(input("Input Integer -> ")) 

if x > 5:
	x += 6
	if x < 15:
		print(x)
		if x > 13:
			print("arrived")

		else:
			x = x - 5
			print(x)