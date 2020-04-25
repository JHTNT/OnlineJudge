t = int(input())
for i in range(t):
    n = int(input())
    if (n / 2) % 2 == 1:
        print("NO")
        continue
    l = [None] * n
    for i in range(n // 2):
        l[n // 2 + i] = i * 2 + 1
        l[i] = (i + 1) * 2
    l[-1] += n // 2
    print("YES")
    print(*l, sep=" ")