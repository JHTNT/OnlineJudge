while True:      #TLE(6s)未解決
    n = int(input())
    if n == 0:
        break
    count = 0
    if n % 2 == 0:
        m = n // 2
    else:
        m = (n + 1) // 2
    for i in range(m, 0, -1):
        S = 0
        S += i
        for j in range(i - 1, 0, -1):
            S += j
            if S == n:
                count += 1
            elif S > n:
                break
    print(count)