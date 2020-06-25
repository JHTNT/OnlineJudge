n, k = map(int, input().split())
a = list(map(int, input().split()))
S = 0
score = a[k - 1]
for i in a:
    if i >= score and i > 0:
        S += 1
print(S)