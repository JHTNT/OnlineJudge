try:
    while True:
        score = list(map(int, input().split()))
        n = score.pop(0)
        S = 0
        for i in range(n):
            S += score[i]
        if S / n > 59:
            print("no")
        else:
            print("yes")
except EOFError:
    pass