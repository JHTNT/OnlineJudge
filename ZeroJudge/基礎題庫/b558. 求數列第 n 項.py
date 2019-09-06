import sys
while True:
    x = (sys.stdin.readline().strip("\n"))
    if not x:
        break
    x = int(x)
    print(1 + x * (x - 1) // 2)