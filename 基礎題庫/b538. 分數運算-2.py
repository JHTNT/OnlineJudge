from fractions import Fraction # 內建分數函式庫
try:
    while True:
        a, b, c, d, opr = input().split()
        frac1 = Fraction(int(a), int(b))
        frac2 = Fraction(int(c), int(d))
        if opr == "+":
            print(frac1 + frac2)
        elif opr == "-":
            print(frac1 - frac2)
        elif opr == "*":
            print(frac1 * frac2)
        elif opr == "/":
            print(frac1 / frac2)
except:
    pass