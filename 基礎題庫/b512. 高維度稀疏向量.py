try:
    while True:
        l1 = list(input().split())
        l2 = list(input().split())
        dict1 = {}
        dict2 = {}
        S = 0
        for i in l1:
            a, b = list(map(int, i.split(":")))
            if a == 0 and b == 0:
                pass
            dict1.update({a:b})
        for j in l2:
            a, b = list(map(int, j.split(":")))
            if a == 0 and b == 0:
                pass
            dict2.update({a:b})
        for k in dict1:
            if k in dict2:
                S += dict1[k] * dict2[k]
        print(S)
except:
    pass