t = int(input())
for i in range(t):
    n = int(input())
    x = 3
    while n % x:
        x = x * 2 + 1
    print(n // x)