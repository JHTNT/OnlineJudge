try:
    while True:
        num = []
        n = int(input())
        num = map(int, input().split())
        print(max(num))
except EOFError:
    pass