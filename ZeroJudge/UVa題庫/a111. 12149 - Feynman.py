try:
    while True:
        n = int(input())
        if n == 0:
            pass
        else:
            print(n * (n + 1) * (2 * n + 1) // 6) # 平方總和
except EOFError:
    pass