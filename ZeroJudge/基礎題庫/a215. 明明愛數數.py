try:
    while True:
        n, m = map(int, input().split())
        S = 0
        x = 0
        if n > m:
            print("1")
            pass
        else:
            while S <= m:
                S += n + x
                x += 1
            print(x)
except EOFError:
    pass