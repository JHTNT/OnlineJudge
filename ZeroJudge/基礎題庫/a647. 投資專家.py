try:
    while True:
        n = int(input())
        for i in range(n):
            before, after = map(int, input().split())
            percent = (after - before) / before * 100
            if percent > 0:
                percent += 0.00001
            elif percent < 0:
                percent -= 0.00001
            if percent <= -7 or percent >= 10:
                print("{0:.02f}% dispose".format(round(percent, 2)))
            else:
                print("{0:.02f}% keep".format(round(percent, 2)))
except EOFError:
    pass