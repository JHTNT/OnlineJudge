n = int(input())
for i in range(n):
    l = input()
    if len(list(l)) <= 10:
        print(l)
    else:
        print(l[0] + str(len(list(l)) - 2) + l[-1])