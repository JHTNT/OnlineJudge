import datetime
try:
    while True:
        x1, y1, z1 = map(int, input().split())
        x2, y2, z2 = map(int, input().split())
        day1 = datetime.date(x1, y1, z1)
        day2 = datetime.date(x2, y2, z2)
        result = day2 - day1
        print(str(abs(result.days)))
except EOFError:
    pass
