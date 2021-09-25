from sys import stdin

class Solution:
    def remove_extra_spaces(self, s):
        length = len(s)
        slow, fast = 0, 0
        # 去除字串前面的空格
        while fast < length and s[fast] == " ":
            fast += 1
        # 去除中間多於空格
        for _ in range(fast, length):
            # 除了開頭以外第一個出現的連續空格至少在 index 2
            if fast > 1 and s[fast] == s[fast - 1] and s[fast] == " ":
                fast += 1
            else:
                s[slow] = s[fast]
                slow += 1
                fast += 1
        # 去除後面的空格
        if slow > 1 and s[slow - 1] == " ":
            return s[:slow - 1]
        else:
            return s[:slow]

    def reverseWords(self, s: str) -> str:
        s = list(s)
        s = self.remove_extra_spaces(s)[::-1]
        length = len(s)         # 獲取新的長度
        start = 0           # 紀錄新單字開始的位置
        while start < length:
            end = start
            # 遇到空格後將此單字反轉
            while end < length and s[end] != " ": end += 1
            if start == 0:
                s[start:end] = s[end - 1::-1]
            else:
                s[start:end] = s[end - 1:start - 1:-1]
            start = end + 1
        return "".join(s)


def main():
    for line in stdin:
        s = line.strip()
        print(Solution().reverseWords(s))

if __name__ == '__main__':
    main()