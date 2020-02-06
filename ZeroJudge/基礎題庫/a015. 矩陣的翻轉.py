try:
    while True:
        m, n = map(int, (input().split()))
        matrix = []
        for i in range(m):
            matrix.append(list(input().split()))
        for i in range(n):
            for j in range(m):
                print(matrix[j][i], end=" ")
            print()
except EOFError:
    pass