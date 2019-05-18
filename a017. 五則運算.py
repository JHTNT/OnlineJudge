import sys
for x in sys.stdin:
	x = x.replace("/", "//")
	print(int(eval(x)))