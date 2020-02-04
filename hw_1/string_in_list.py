
my_list = []

size = int(input("Items in list: "))

for i in range(size):
	user_in = str(input("List of Strings: "))
	my_list.append(user_in)


print(my_list)


search = input("Search for: ")


for j in range(size):
	if search in my_list[j]:
		print(j)

if search not in my_list:
	print("String not found")