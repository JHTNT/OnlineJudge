try: # NA (score:80%)
    def count_num(l):
        count = {}
        for i in l:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        max_appear = 0
        for v in count.values():
            if v > max_appear:
                max_appear = v
        if max_appear == 1:
            return
        for k, v in count.items():
            if v == max_appear: # 測資第4、10行錯誤
                print(str(k) + " " + str(v))
    while True:
        n = int(input())
        l = list(map(int, input().split()))
        count_num(l)
except EOFError:
    pass