import sys
for r in sys.stdin:
    r = r.strip()
    if r:
        r = float(r)
        R = r * 9 / 5 + 32
        print("{:g}".format(R)) # 格式化