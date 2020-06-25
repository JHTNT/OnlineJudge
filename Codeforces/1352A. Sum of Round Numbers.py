t = int(input())
for i in range(t):
    n = int(input())
    l = len(list(str(n)))
    S = 1
    num = ""
    while n > 10:
        if n % (10 ** (l - 1)) == 0:
            break
        if n > (10 ** (l - 1)):
            num = num + str(n - n % (10 ** (l - 1))) + " "
            n = n % (10 ** (l - 1))
            S += 1
            l -= 1
        else:
            l -= 1
    num += str(n)
    print(S)
    print(num)