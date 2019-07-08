import sys
for x in sys.stdin:
    x = x.strip()
    if x:
        n, m = map(int, x.split())
        k = 1
        if m == 0: # 第五題有一個G8測資n = 2147483647, m = 0
            print("Go Kevin!!")
        else:
            while n > 0:
                n -= k 
                k += m
            if n == 0:
                print("Go Kevin!!")
            else:
                print("No Stop!!")