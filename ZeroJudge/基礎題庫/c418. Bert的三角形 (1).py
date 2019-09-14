try:
    while True:
        n = int(input())
        for i in range(1, n + 1):
            print("*" * i)
except EOFError:
    pass