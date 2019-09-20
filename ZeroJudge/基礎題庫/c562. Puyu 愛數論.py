try:
    while True:
        n = list(input())
        print(n.count("0") + n.count("6") + n.count("8") * 2 + n.count("9"))
except EOFError:
    pass