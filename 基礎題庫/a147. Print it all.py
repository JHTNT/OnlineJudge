while True:
    x = int(input())
    if x == 0:
        break
    else:
        print(" ".join([str(x) for x in range(1, x) if x % 7 != 0]))