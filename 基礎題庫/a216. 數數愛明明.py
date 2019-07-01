try:
    while True:
        x = int(input())
        f = x * (x + 1) // 2
        g = x * (x + 1) * (x + 2) // 6
        print(f, g)
except EOFError:
    pass