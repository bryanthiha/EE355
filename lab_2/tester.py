# Bryan Thiha 	6002228585

import sys
import subprocess
from random import *


with open("results.txt", "w") as f:						# openning file to write to
														# 'with' is good practice because it closes for you automatically
	for i in range(10000):

		x = uniform(-100, 100)
		y = uniform(-100, 100)

		d = uniform(0,100)

		Zcomputed = (x*x) + (y*y)

		Zblackbox = float(subprocess.check_output(["./blackbox", str(x), str(y), str(d)]))	

		difference = abs(Zcomputed - Zblackbox)

		f.write("  %f\n" % difference)



