from sys import stdin

for x in stdin:
    for _ in range(int(x)):
        n, m = map(int, stdin.readline().split())
        right, bottom, left, top = n - 1, n - 1, -1, 0 # 設定邊界
        num = [[None for i in range(n)] for j in range(n)] # 初始化二維矩陣
        count, max = 0, n * n
        while count < max:
            left += 1 # 邊界右縮 1 欄
            for i in range(left, right + 1):
                count += 1
                num[top][i] = count
            top += 1
            for j in range(top, bottom + 1):
                count += 1
                num[j][right] = count
            right -= 1
            for i in range(right, left - 1, -1):
                count += 1
                num[bottom][i] = count
            bottom -= 1
            for j in range(bottom, top - 1, -1):
                count += 1
                num[j][left] = count
        if m == 1:
            for i in range(n):
                output = ""
                for j in range(n):
                    output += f"{num[i][j]: {5}}"
                print(output)
        else: # 逆時針方向
            for i in range(n):
                output = ""
                for j in range(n):
                    output += f"{num[j][i]: {5}}"
                print(output)
        print()