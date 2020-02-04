# Bryan Thiha

# Write a python code that gets two inputs: 1) a list of strings, and 2) a string . 
# The code then checks to see if that string is in the list, 
# If TRUE it prints out the indexes of the string. Otherwise print out "String was not found". 


my_list = []

user_in = str(input("Input String: "))

while user_in != "done":						#Adds all strings user inputs into list until they hit done
	my_list.append(user_in)
	user_in = str(input("Input String: "))

print(my_list)

search = input("Search for: ")

list_length = len(my_list)	

for j in range(list_length):				#Goes through list to search for index of searched string
	if search in my_list[j]:
		print(j)

if search not in my_list:
	print("String not found")