try:
	while True:
		x = int(input())
		if x <= 10:
			s = x * 6
		elif x <= 20 and x >=11:
			s  = 60 + x * 2
		elif x <= 40 and x >= 21:
			s = 80 + x * 1
		elif x > 40:
			s = 100
		print(s)
except EOFError:
	pass