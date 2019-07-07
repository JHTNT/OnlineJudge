try:
    while True:
        x = input()
        if x:
            hour, minute = map(int, x.split())
            hour += 2
            minute += 30
            if minute >= 60:
                hour += 1
                minute -= 60
            if hour >= 24:
                hour -= 24
            print("%02d:%02d" %(hour, minute))
except EOFError:
    pass