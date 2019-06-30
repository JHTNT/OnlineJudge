try:
    while True:
        n = input()
        x = list(map(int, input().split()))
        x.sort()
        print(*x, sep=" ")
except EOFError:
    pass 