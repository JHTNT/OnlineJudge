from sys import stdin

def upper_case(letter):
    if letter.isupper():
        return True
    elif letter.islower():
        return False
    else:
        return None

for line in stdin:
    k = int(line)
    string = stdin.readline().strip()
    max_len, cur_len = 0, 0
    str_len = len(string)
    pre_case, cur_case = None, None
    case_len = 0        # 當前字母 case 長度
    # k 為 1 另外處理
    if k == 1:
        for i in string:
            cur_case = upper_case(i)        # 取得當前字母大小寫
            # 若大小寫不變則重置 cur_len
            if cur_case == pre_case:
                max_len = max(cur_len, max_len)
                cur_len = 1
            else:
                cur_len += 1
            pre_case = cur_case
        max_len = max(cur_len, max_len)
    else:
        for i in string:
            cur_case = upper_case(i)
            if cur_case == pre_case:
                case_len += 1
                # 當前 case 的長度達到 k 就累加
                if case_len == k:
                    cur_len += k
                    max_len = max(cur_len, max_len)
                # 超過 k 就不連續，當前長度只能等於 k
                elif case_len > k:
                    cur_len = k
            else:
                # 小於 k 不計入
                if case_len < k:
                    cur_len = 0
                case_len = 1        # 當前字母為新 case_len 的第一個
            pre_case = cur_case
    print(max_len)