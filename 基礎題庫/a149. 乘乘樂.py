try:
    while True:
        n = int(input())
        for i in range(n):
            num = list(input())
            S = int(num[0])
            for j in range(1, len(num)):
                S = S * int(num[j])
            print(S)
except EOFError:
    pass