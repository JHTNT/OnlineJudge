try:
    while True:
        n = input()
        if n:
            n = int(n)
            for i in range(n):
                x, y = input().split()
                l = []
                for j in range(int(x)):
                    l += input().split()
                if l == l[::-1]:
                    print("go forward")
                else:
                    print("keep defending")
except EOFError:
    pass