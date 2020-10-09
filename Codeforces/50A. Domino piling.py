m, n = map(int, input().split())
if m % 2 == 0 or n % 2 == 0:
    print(m * n // 2)
else:
    print((m * n - 1) // 2)