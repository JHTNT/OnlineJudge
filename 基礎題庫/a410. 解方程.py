try:
    a1, b1, c1, a2, b2, c2 = map(int, input().split())
    delta = a1 * b2 - a2 * b1 #克拉瑪公式
    delta_x = c1 * b2 - b1 * c2
    delta_y = a1 * c2 - c1 * a2
    if delta != 0:
        x = round(int(delta_x) / int(delta), 2)
        y = round(int(delta_y) / int(delta), 2)
        if (x * 100) % 100 != 0 or (y * 100) % 100 != 0:
            print("x=" + str(x) + "\ny=" + str(y))
        else:
            print("x=" + str(x) +"0\ny=" + str(y) + "0")
    elif delta == delta_x == delta_y:
        print("Too many")
    else:
        print("No answer")
except EOFError:
    pass