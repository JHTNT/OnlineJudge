try:
	while True:
		n = int(input())
		x = list(map(int, input().split()))
		order = x
		order.sort()
		print(*order, sep=" ")
		max, min = -1, 101
		for i in x:
			if i < 60 and i > max:
				max = i
			elif i >= 60 and i < min:
				min = i
		if max > -1:
			print(max)
		else:
			print("best case")
		if min  < 101:
			print(min)
		else:
			print("worst case")
except EOFError:
	pass