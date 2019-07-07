try: # 整個不知道在寫什麼
    while True:
        n = int(input())
        k, k_tem, a, d = 0, 0, 0, 0
        while n > 0:
            s = input()
            if s:
                if s == "Get_Kill":
                    k_tem += 1
                    if k_tem < 3:
                        print("You have slain an enemie.")
                    elif k_tem == 3:
                        print("KILLING SPREE!")
                    elif k_tem == 4:
                        print("RAMPAGE~")
                    elif k_tem == 5:
                        print("UNSTOPPABLE!")
                    elif k_tem == 6:
                        print("DOMINATING!")
                    elif k_tem == 7:
                        print("GUALIKE!")
                    elif k_tem >= 8:
                        print("LEGENDARY!")
                elif s == "Get_Assist":
                    a += 1 # 不知為何測資會少算一次
                elif s == "Die":
                    if k_tem < 3:
                        print("You have been slained.")
                    else:
                        print("SHUTDOWN.")
                    k += k_tem
                    k_tem = 0
                    d += 1
            n -= 1
        k += k_tem
        print(k, d, a, sep="/")
except EOFError:
    pass