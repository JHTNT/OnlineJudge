try:
    while True:
        x = list(input())
        ascii = [0] * 26
        count = 0
        for i in x:
            if i.isupper():
                i = i.lower()
            if ord(i) >= 97 and ord(i) <= 122:
                ascii[ord(i) - 97] += 1
        if sum(ascii) == 0:
            print("yes !")
            continue
        for i in ascii:
            if i % 2:
                count += 1
        if count <= 1:
            print("yes !")
        else: print("no...")
except EOFError:
    pass