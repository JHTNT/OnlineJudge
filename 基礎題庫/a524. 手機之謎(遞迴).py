import sys
def recursion(lt, use, current, n):
    if current == n:
        for i in range(n):
            print("{0}".format(lt[i]), end="")
        print()
    else:
        for i in range(n - 1, -1, -1):
            if use[i] == 0 :
                use[i] = 1
                lt[current] = i + 1
                recursion(lt, use, current + 1, n)
                use[i] = 0
            else:
                pass

lt = [0] * 8
use = [0] * 8

for n in sys.stdin:
    if n[0] != "\n": # 解決測資有空行問題
        n = int(n)
        use = [0] * n
        recursion(lt, use, 0, n)