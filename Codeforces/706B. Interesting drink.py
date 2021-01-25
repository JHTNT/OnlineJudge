t = int(input())
price = list(map(int, input().split()))
price.sort(reverse=True)
price.append(int(-1))
for i in range(int(input())):
    m = int(input())
    if m > price[0]:
            print(t)
            continue
    for j in range(t + 1):
        if m >= price[j]:
            print(t - j)
            break