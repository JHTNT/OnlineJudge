t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    if l[0] > 0: positive = True
    else: positive = False

    ans = [l[0]]

    for i in l[1:]:
        if positive == True and i < 0:
            ans.append(i) # 使序列最長
            positive = False # 正負相間
        elif positive == True and ans[-1] < i:
            ans[-1] = i # 使 sum 最大化
        elif positive == False and i > 0:
            ans.append(i)
            positive = True
        elif positive == False and ans[-1] < i:
            ans[-1] = i
    print(sum(ans))