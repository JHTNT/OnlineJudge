t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    if k < n:
        print(k)
        pass
    else:
        x = k // (n - 1)
        if k % (n - 1) == 0:
            print(n * x - 1)
        else:
            print(n * x + k % (n - 1))