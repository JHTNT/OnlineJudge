a = list(map(int, input().split()))
n = a.pop(0)
S = 0
for i in a:
    S += abs(i - 2) ** 2
print(S)