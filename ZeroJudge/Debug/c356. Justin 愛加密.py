try: # NA(應該是記憶體爆掉)
	while True:
		n = int(input())
		l = input()
		space = 0
		temp = []
		print(l[0], end="")
		for i in range(1, n):
			string = list(l[n * i:n * (i + 1)])
			#print(string)
			print(string[i], end="")
		print()
except EOFError:
    pass
