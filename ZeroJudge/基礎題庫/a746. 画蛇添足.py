from sys import stdin

for x in stdin:
    if x == "\n": continue
    n, m = map(int, x.split())
    ground = [[" " for i in range(n)] for i in range(n)]
    coor = []
    for i in range(m): # 讀取所有座標
        coor.append(list(map(int, stdin.readline().split())))
    for i in range(1, m):
        x, y = coor[i][0], coor[i][1]
        if x == coor[i - 1][0]: # 縱向移動
            for j in range(min(y, coor[i - 1][1]), max(y, coor[i - 1][1]) + 1):
                ground[x - 1][j - 1] = "*"
        else: # 橫向移動
            for j in range(min(x, coor[i - 1][0]), max(x, coor[i - 1][0]) + 1):
                ground[j - 1][y - 1] = "*"
    del coor # 釋放記憶體空間
    print("-" * (n + 2))
    for i in range(n):
        print("|", "".join(ground[i]), "|", sep="")
    print("-" * (n + 2))
    del ground