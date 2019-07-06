try:
    while True:
        n = int(input())
        for i in range(n):
            lst = list(map(int, input().split()))
            x = (lst[2] - lst[0]) * 60 + (lst[3] - lst[1]) - lst[4]
            if x >= 0:
                print("Yes")
            else:
                print("No")
except EOFError:
    pass