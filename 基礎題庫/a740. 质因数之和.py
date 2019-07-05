try:
    while True:
        x = input()
        if x:
            x = int(x)
            S = 0
            if x > 1:
                for i in range(2, x + 1):
                    if i > 2000000000 ** 0.5:
                        S += x
                        break
                    while x % i == 0:
                        S += i
                        x = x // i
            print(S)
except EOFError:
    pass