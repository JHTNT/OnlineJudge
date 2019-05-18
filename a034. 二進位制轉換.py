try:
	while True:
		x = int(input())
		a = []
		while x > 1:
			a.append(x % 2)
			x = int(x / 2)
		a.append(x % 2)
		a.reverse()
		print(*a, sep="")
except EOFError:
	pass