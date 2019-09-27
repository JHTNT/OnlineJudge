import sys
try:
    while True:
        l = list(input().split())
        n = l.pop(0)
        print(*l, sep=" " + n + " ")
except EOFError:
    pass