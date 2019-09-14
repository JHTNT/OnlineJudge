try: # 	NA (score:80%)
    while True:
        x = input()
        l = list(map(int, input().split()))
        print(max(l) - min(l)) # 最大值位置需小於最小值
except EOFError:
    pass