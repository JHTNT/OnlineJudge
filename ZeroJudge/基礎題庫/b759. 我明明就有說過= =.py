try:
    while True:
        X = list(input())
        for i in range(0, len(X)):
            x = list(X)
            y = x[:i]
            x[:i] = []
            x.extend(y)
            print(*x, sep="")
except EOFError:
    pass