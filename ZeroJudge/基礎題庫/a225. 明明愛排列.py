from sys import stdin

for x in stdin:
    n = int(x)
    num = list(map(int, stdin.readline().split()))
    num.sort(key=lambda m: (m % 10, -m)) # 若個位數相同則由大到小排序
    print(*num)