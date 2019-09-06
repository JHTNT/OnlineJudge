try:
    while True:
        name = input()
        print("Hey", name)
except EOFError:
    pass