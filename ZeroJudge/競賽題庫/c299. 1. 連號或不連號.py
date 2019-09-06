try:
	while True:
		w = input()
		x = list(map(int, list(w.split())))
		n = x[0]
		del x[0]
		x.sort()
		same = "yes"
		for i in range(len(x) - 1):
			if int(x[i]) + 1 == int(x[i + 1]):
				continue
			else:
				 same = "no"
		print(x[0], x[len(x) - 1], same)
except 
