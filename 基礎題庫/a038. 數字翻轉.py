try:
	while True:
		x = input()
		y = list(x)
		s = 0
		for i in range(0, len(y)):
			s = s + int(y[i]) * (10 ** i)
		print(s)
except EOFError:
	pass