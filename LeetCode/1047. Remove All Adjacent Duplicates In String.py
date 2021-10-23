from sys import stdin

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        # 將字串的字母逐一加入堆疊，遇到連續重複就改為 pop
        for i in s:
            if stack and stack[-1] == i:
                stack.pop()
            else:
                stack.append(i)
        return "".join(stack)

def main():
    for line in stdin:
        s = line.strip()
        print(Solution().removeDuplicates(s))

if __name__ == '__main__':
    main()