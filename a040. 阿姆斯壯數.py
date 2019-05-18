try:
	while True:
		m, n = map(int, input().split())
		y = 0
		for i in range(m, n + 1):
			s = 0
			k = list(str(i))
			for j in range(0, len(k)):
				s = s + int(k[j]) ** len(k)
			if i == s:
				print(i, end=" ")
				y = y + 1
			else:
				continue
		if y == 0:
			print("none")
		else:
			print("\n")
except EOFError:
	pass