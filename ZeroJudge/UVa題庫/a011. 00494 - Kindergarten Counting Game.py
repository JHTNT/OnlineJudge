try:
    while True:
        n = input()
        out = ""
        for i in n:
            if i.isalpha() == False:
                out += " " # 如果非英文字母則替換為空格
            else:
                out += i
        print(len(out.split()))
except EOFError:
    pass