try:
    while True:
        n = int(input())
        x_y = []
        for i in range(n):
            x, y = map(int, input().split())
            a = [x, y]
            x_y.append(a)
        x_y.sort()
        for j in x_y:
            print(*j, sep=" ")
except EOFError:
    pass