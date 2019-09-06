import math
try:
    while True:
        n = int(input())
        print(int(math.log2(n) + 1)) # 二分搜尋法
except EOFError:
    pass