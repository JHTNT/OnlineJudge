try:
    while True:
        n = int(input())
        price = 1
        S = 0
        qua = list(map(int, input().split()))
        for i in range(n):
            S += qua[i] * price
            price += 1
        print(S)
except EOFError:
    pass