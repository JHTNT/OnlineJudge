try:
    number = [0] * 201 # 建表(應該是)
    number[0] = 1
    for i in range(1, 201):
        for j in range(i, 201):
            number[j] += number[j - i]
    while True:
        n = int(input())
        print(number[n])
except EOFError:
    pass