from sys import stdin

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for bracket in s:   
            # 將左括號對應的右括號存入堆疊
            if bracket == "(":
                stack.append(")")
            elif bracket == "[":
                stack.append("]")
            elif bracket == "{":
                stack.append("}")
            # 左括號數量不足或括號不符合就回傳 False
            elif not stack or stack[-1] != bracket:
                return False
            else:
                stack.pop()         # 括號配對成功就 pop

        # 如果遍歷後堆疊剛好為空就回傳 True
        return True if not stack else False
        

def main():
    for line in stdin:
        s = line.strip()
        print(Solution().isValid(s))

if __name__ == '__main__':
    main()