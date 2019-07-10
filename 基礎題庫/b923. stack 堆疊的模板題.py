try:
    while True:
        n = int(input())
        stack = []
        for i in range(n):
            l = list(input().split())
            if l[0] == "1":
                stack.pop()
            elif l[0] == "2":
                print(int(stack[-1]))
            elif l[0] == "3":
                stack.append(l[1])
except EOFError:
    pass