try:
    while True:
        x = list(input())
        password = []
        for i in range(len(x) - 1):
            if i == 0:
                x[i] = ord(x[i])
            x[i + 1] = ord(x[i + 1])
            password.append(abs(x[i] - x[i + 1]))
        print(*password, sep="")
except EOFError:
    pass