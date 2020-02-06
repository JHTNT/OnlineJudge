try: # 函式參考解題報告
    num = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
    def r2n(x):
        S = 0
        for i in range(len(x)):
            S += num[x[i]]
            if i != len(x) - 1 and (x[i] == "I" and (x[i + 1] == "V" or x[i + 1] == "X")): S -= 2
            elif i != len(x) - 1 and (x[i] == "X" and (x[i + 1] == "L" or x[i + 1] == "C")): S -= 20
            elif i != len(x) - 1 and (x[i] == "C" and (x[i + 1] == "D" or x[i + 1] == "M")): S -= 200
        return S

    def n2r(x):
        x, roma = str(x), ""
        for i in range(len(x)):
            tmp = int(x[i]) * (10 ** (len(x) - 1 - i))
            if str(tmp)[0] != "9" and str(tmp)[0] != "4":
                i = 6
                while tmp != 0:
                    if tmp - list(num.values())[i] >= 0:
                        roma += list(num.keys())[i]
                        tmp -= list(num.values())[i]
                    else: i -= 1
            elif tmp == 4000: roma += "MMMM"
            elif tmp == 900: roma += "CM"
            elif tmp == 400: roma += "CD"
            elif tmp == 90: roma += "XC"
            elif tmp == 40: roma += "XL"
            elif tmp == 9: roma += "IX"
            elif tmp == 4: roma += "IV"
        return roma

    while True:
        n = input()
        if n == "#":
            break
        a, b = n.split()
        difference = abs(r2n(a) - r2n(b))
        if difference == 0:
            print("ZERO")
        else:
            print(n2r(difference))
except EOFError:
    pass