S = 0
for i in range(int(input())):
    x = list(map(int, input().split()))
    if sum(x) >= 2:
        S += 1
print(S)