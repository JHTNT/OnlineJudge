from decimal import Decimal, ROUND_HALF_UP, getcontext # NA (score:50%)
try:
    while True:
        getcontext().prec = 2
        n = int(input())
        for i in range(n):
            before, after = map(int, input().split())
            percent = (after - before) / before * 100 # 四捨五入問題未解決
            if float(percent) <= -7 or float(percent) >= 10:
                print(str(percent) + "%" + " dispose")
            else:
                print(str(percent) + "%" + " keep")
except EOFError:
    pass