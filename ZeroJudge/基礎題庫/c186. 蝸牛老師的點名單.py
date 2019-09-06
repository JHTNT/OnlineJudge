try:
    while True:
        name = list(input().split())
        print(*name, sep="\n")
except EOFError:
    pass