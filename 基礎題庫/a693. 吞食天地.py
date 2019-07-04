try:
    while True:
        n, m = map(int, input().split())
        food = list(map(int, input().split()))
        food_sum = []
        S = 0
        for i in range(len(food)): # 建表
            food_sum.append(S)
            S += food[i]
        food_sum.append(S)
        for j in range(m):
            l, r = map(int, input().split())
            print(food_sum[r] - food_sum[l - 1]) # l 項到 r 項的總和
except EOFError:
    pass