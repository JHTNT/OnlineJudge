try:
    while True:
        n = int(input())
        for i in range(1, n + 1):
            print("_" * (n - i), end="")
            print("*" * i)
except EOFError:
    pass