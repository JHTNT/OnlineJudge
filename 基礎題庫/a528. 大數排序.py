try:
    while True:
        n = int(input())
        num = []
        for i in range(n):
            x = int(input())
            num.append(x)
        num.sort()
        print(*num, sep="\n")
except EOFError:
    pass