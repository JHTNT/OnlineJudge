try:
    dic = ["鼠", "牛", "虎", "兔", "龍", "蛇", "馬", "羊", "猴", "雞", "狗", "豬"]
    while True:
        x = int(input())
        if x < 0:
            print(dic[x % 12])
        else:
            print(dic[(x - 1) % 12])
except EOFError:
    pass