import sys
import subprocess
from random import *


#z_list = []

with open("results.txt", "w") as f:
	
	for i in range(10000):

		x = uniform(-100, 100)
		y = uniform(-100, 100)

		d = uniform(0,100)

		Zcomputed = (x*x) + (y*y)

		Zblackbox = float(subprocess.check_output(["./blackbox", str(x), str(y), str(d)]))	
		#print(x,y,d)

		difference = abs(Zcomputed - Zblackbox)

		f.write("  %f\n" % difference)



	#z_list.append(difference)
	#print(difference)

# with open("results.txt", "w") as f:
# 	for j in range(len(z_list)):

# 		f.write("  %s\n" % z_list[j])