try:
    while True:
        n = int(input())
        l = input()
        print(l[0], end="")
        space = 0
        for i in range(n - 1):
            space += n + 1
            print(l[space], end="")
        print()
except EOFError:
    pass