try:
	while True:
		a = input()
		x = list(a)
		y = list(a)
		y.reverse()
		if x == y:
			print("yes")
		else:
			print("no")
except EOFError:
	pass