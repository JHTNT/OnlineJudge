def main():
    from sys import stdin

    output = ""
    for x in stdin:
        if x.strip() == "": continue
        ans = x.split()
        num = {str(i): 0 for i in range(10)} # 轉換成字串以節省步驟
        for i in ans: num[i] += 1 # 用集合計算數字出現次數
        
        _ = int(stdin.readline())
        for j in range(_):
            guess = stdin.readline().split()
            a, b, tmp = 0, 0, num.copy()
            incorrect = [] # 紀錄數字正確但位置錯誤
            for i in range(4):
                m = guess[i]
                if tmp[m]: # 如果答案有 m
                    if m == ans[i]:
                        a += 1
                        tmp[m] -= 1
                    else: incorrect.append(m)
            for i in incorrect:
                if tmp[i]:
                    b += 1
                    tmp[i] -= 1
            output += f"{a}A{b}B\n" # 讓答案一次輸出以節省時間
    print(output)

main()