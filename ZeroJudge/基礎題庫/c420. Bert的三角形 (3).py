try:
    while True:
        n = int(input())
        for i in range(1, n + 1):
            print("_" * (n - i), end="")
            print("*" * (2 * i - 1), end="")
            print("_" * (n - i))
except EOFError:
    pass