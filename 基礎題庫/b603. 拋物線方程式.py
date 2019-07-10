try:
    def GCD(x,y):
        while y > 0:
            x, y = y, x % y
        return x
    while True:
        x_y = list(map(int, input().split()))
        a = x_y[3] - x_y[1] # 代公式，網路找的
        b = -2 * x_y[0] * (x_y[3] - x_y[1])
        c = (x_y[3] - x_y[1]) * (x_y[0] ** 2) + x_y[1] * ((x_y[2] - x_y[0]) ** 2)
        d = (x_y[2] - x_y[0]) ** 2
        gcd = GCD(GCD(GCD(a, b), c), d)
        print("%dy = %dx^2 + %dx + %d" %(d // gcd, a // gcd, b // gcd, c // gcd))
except EOFError:
    pass