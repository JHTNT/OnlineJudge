try:
    def GCD(a, b):
        while b > 0:
            a, b = b, a % b
        return a
    while True:
        x = input().split()
        if len(x) == 2: #有一筆測資a, b不同行
            a = int(x[0])
            b = int(x[1])
            print(GCD(a, b))
except EOFError:
    pass