from sys import stdin

class Solution:
    def get_next(self, needle):
        # 根據 needle 建立 next 陣列
        next = [0] * len(needle)
        j = 0
        next[0] = 0
        for i in range(1, len(needle)):
            while j > 0 and needle[i] != needle[j]:
                j = next[j - 1]
            if needle[i] == needle[j]:
                j += 1
            next[i] = j
        return next

    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0: return 0       # 若 needle 為空字串直接回傳 0
        next = self.get_next(needle)
        j = 0
        for i in range(len(haystack)):
            while j > 0 and haystack[i] != needle[j]:
                j = next[j - 1]
            if haystack[i] == needle[j]:
                j += 1
            if j == len(needle):
                return (i - len(needle) + 1)
        return -1

def main():
    for line in stdin:
        haystack = line.strip()
        needle = stdin.readline().strip()
        print(Solution().strStr(haystack, needle))

if __name__ == '__main__':
    main()

# 詳細思路見 https://programmercarl.com/0028.实现strStr.html