try: # WA (line:3)
    while True:
        a = list(map(int, input().split()))
        print((a[0] * 2 + a[1]) ** 2 - 3 * a[0] ** 2)
except EOFError:
    pass