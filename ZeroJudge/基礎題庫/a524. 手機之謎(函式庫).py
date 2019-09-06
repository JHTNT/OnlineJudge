import sys
import itertools

for s in sys.stdin:
    s = s.strip()
    if s:
        for i in list(itertools.permutations(range(1, int(s) + 1), int(s)))[::-1]:
            print("".join(map(str, i)))