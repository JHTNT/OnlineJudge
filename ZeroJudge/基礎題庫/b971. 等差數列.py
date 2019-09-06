try:
    while True:
        a1, an, d = map(int, input().split())
        if d >= 0:
            for i in range(a1, an + 1, d):
                print(i, end=" ")
        elif d < 0:
            for i in range(a1, an - 1, d):
                print(i, end=" ")
except EOFError:
    pass