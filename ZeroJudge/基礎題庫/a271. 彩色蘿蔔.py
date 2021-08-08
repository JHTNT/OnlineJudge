from sys import stdin

for i in range(int(stdin.readline())):
    info = list(map(int, stdin.readline().split()))
    info[2], info[3] = -info[2], -info[3]
    posion = 0
    behave = list(map(int, stdin.readline().split()))
    weight = info[5]
    for j in behave:
        weight -= info[4] * posion
        if j == 0:
            continue
        if weight <= 0:
            break
        weight += info[j - 1]
        if weight <= 0:
            break
        if j == 4:
            posion += 1
    if weight <= 0:
        print("bye~Rabbit")
    else:
        print(f"{weight}g")