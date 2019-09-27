try:
    dic1 = ["庚", "辛", "壬", "癸", "甲", "乙", "丙", "丁", "戊", "己"]
    dic2 = ["申", "酉", "戌", "亥", "子", "丑", "寅", "卯", "辰", "巳", "午", "未"]
    while True:
        x = int(input())
        print(dic1[(x - 1800) % 10] + dic2[(x - 1800) % 12])
except EOFError:
    pass