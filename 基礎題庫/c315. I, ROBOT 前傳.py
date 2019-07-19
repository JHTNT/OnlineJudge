try:
    while True:
        n = int(input())
        x, y = 0, 0
        for i in range(n):
            direct, step = map(int, input().split())
            if direct == 0:
                y += step
            elif direct == 1:
                x += step
            elif direct == 2:
                y -= step
            elif direct == 3:
                x -= step
        print(x, y)
except EOFError:
    pass