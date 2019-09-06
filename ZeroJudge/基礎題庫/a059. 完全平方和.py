from math import sqrt
try:
    while True:
        n = int(input())
        for j in range(n):
            a = int(input())
            b = int(input())
            c = int(sqrt(a))
            S = 0
            if c ** 2 < a:
                c += 1
            num = c ** 2
            while c ** 2 <= b:
                S += num
                num += c * 2 + 1
                c += 1
            print("Case %d: %d" %(j + 1, S)) #%d為字串格式化
except EOFError:
    pass
