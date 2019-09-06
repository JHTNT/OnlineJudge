try:
    while True:
        name = list(input().split())
        greet = input()
        for i in name:
            print(greet + ", " + i)
except EOFError:
    pass