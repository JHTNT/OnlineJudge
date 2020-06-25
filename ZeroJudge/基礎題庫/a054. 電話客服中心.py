try:
    while True:
        x = list(map(int, list(input())))
        _dict = {1:"AMW", 2:"KLY", 3:"JVX", 4:'HU', 5:'GT', 6:'FS', 7:'ER', 8:'DOQ', 9:'CIP', 0:'BNZ'}
        c = sum([x[i] * (8 - i) for i in range(8)])
        print(_dict[(10 - x[-1] - c) % 10])
except EOFError:
	pass