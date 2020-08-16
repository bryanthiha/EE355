
with open("hello.txt", "w") as f: 
	f.write("Hello World \n\n")

	for i in range(10):
		f.write("This is line %d \n" % (i+1))

file = open('testfile.txt', 'w')

file.write("This is Super One \n") 
file.write("Welcome to my World ")

file.close()


#z_list.append(difference)
	#print(difference)

# with open("results.txt", "w") as f:
# 	for j in range(len(z_list)):

# 		f.write("  %s\n" % z_list[j])