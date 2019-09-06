try:
    while True:
        n = int(input())
        for i in range(n):
            x, y = map(int, input().split())
            yee = 100 - (abs(x) + abs(y))
            if yee > 0 and yee <= 30:
                print("sad!")
            elif yee > 30 and yee <= 60:
                print("hmm~~")
            elif yee > 60 and yee < 100:
                print("Happyyummy")
            elif yee <=0 or yee >=100:
                print("evil!!")
except EOFError:
    pass