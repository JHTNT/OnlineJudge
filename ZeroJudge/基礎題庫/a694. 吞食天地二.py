from sys import stdin

for x in stdin:
    n, m = map(int, x.split())
    foodSum = [[0] * (n + 1)] # 在上方補一排 0（這樣邊界再往回一排還有東西可以取）
    for i in range(n): # 將食物加總並建表
        row = [int(x) for x in stdin.readline().split()]
        row.insert(0, 0) # 在左方補一個 0
        for j in range(1, n + 1):
            row[j] += row[j - 1] # 向右加總
        row = [x + y for x, y in zip(row, foodSum[i])] # 向下加總
        foodSum.append(row)
    for i in range(m):
        y1, x1, y2, x2 = map(int, stdin.readline().split())
        result = foodSum[y2][x2] - foodSum[y2][x1 - 1] - foodSum[y1 - 1][x2] + foodSum[y1 - 1][x1 - 1]
        print(result)