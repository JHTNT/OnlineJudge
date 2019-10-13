import sys # try/except 輸入太慢
for i in sys.stdin: # 解法一（2s）
    n = int(i)
    for j in range(n):
        x = sys.stdin.readline().strip("\n")
        if x == "0 1 0 1":
            print("A", end="")
        elif x == "0 1 1 1":
            print("B", end="")
        elif x == "0 0 1 0":
            print("C", end="")
        elif x == "1 1 0 1":
            print("D", end="")
        elif x == "1 0 0 0":
            print("E", end="")
        elif x == "1 1 0 0":
            print("F", end="")
    print()

# 解法二（1.1s）
'''
import sys
Dict = {"0 1 0 1":"A", "0 1 1 1":"B", "0 0 1 0":"C", "1 1 0 1":"D", "1 0 0 0":"E", "1 1 0 0":"F"}
for i in sys.stdin:
    n = int(i)
    ans = ""
    for i in range(n):
        sIn = sys.stdin.readline().strip("\n")
        ans += Dict[sIn]
    print (ans)
'''