try:
    while True:
        x, y = map(int, input().split())
        if x > y:
            print(y + 1)
        else:
            print(y)
except EOFError:
    pass 