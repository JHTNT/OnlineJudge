t = int(input())
for k in range(t):
    n, m, x, y = map(int, input().split())
    S = 0
    y = min(y, x * 2) # 若 1*2 磁磚價格大於 1*1，則使用兩個 1*1 替代
    for i in range(n):
        tile = input().split("*")
        for j in range(len(tile)):
            l = len(tile[j])
            S += (l // 2 * y + l % 2 * x)
    print(S)