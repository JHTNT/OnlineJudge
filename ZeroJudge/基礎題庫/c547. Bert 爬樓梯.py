try: # NA (score:33%)
    while True:
        n = int(input())
        def step(n):
            if n == 1:
                return 1
            elif n == 2:
                return 2
            a = 1
            b = 2
            for i in range(3, n + 1):
                temp = b
                b = a + b
                a = temp
            return b
        print(step(n))
except EOFError:
    pass