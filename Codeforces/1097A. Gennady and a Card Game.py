table = input()
hand = [list(i) for i in input().split()]
play = False
for rank, suit in hand:
    if rank == table[0] or suit == table[1]:
        print("YES")
        play = True
        break
if play == False:
    print("NO")