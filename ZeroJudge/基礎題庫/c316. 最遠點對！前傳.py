try:
    while True:
        n = int(input())
        x = [None] * n
        y = [None] * n
        max_dist = 0
        point = []
        for i in range(n):
            x[i], y[i] = map(int, input().split())
        for j in range(n - 1):
            for k in range(j + 1, n):
                if  ((x[j] - x[k]) ** 2 + (y[j] - y[k]) ** 2) ** 0.5 >= max_dist:
                    max_dist = ((x[j] - x[k]) ** 2 + (y[j] - y[k]) ** 2) ** 0.5
                    point = [j, k]
        print(*point, sep=" ")
except EOFError:
    pass