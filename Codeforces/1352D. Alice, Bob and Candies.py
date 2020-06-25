t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(1, a[0], 0)
        continue
    alice = 0
    bob = 0
    move = 0
    eat = 1
    pre = 0
    tmp = 0
    while a != []:
        if eat:
            tmp = a[0]
            a.pop(0)
            while tmp <= pre and a != []:
                tmp += a[0]
                a.pop(0)
            pre = tmp
            eat = 0
            move += 1
            alice += tmp
        else:
            tmp = a[-1]
            a.pop(-1)
            while tmp <= pre and a != []:
                tmp += a[-1]
                a.pop(-1)
            pre = tmp
            eat = 1
            move += 1
            bob += tmp
    print(move, alice, bob)