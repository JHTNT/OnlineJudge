from sys import stdin

class Solution:
    def get_next(self, next, s):
        j = 0
        for i in range(1, len(next)):
            while j > 0 and s[i] != s[j]:
                j = next[j - 1]
            if s[i] == s[j]:
                j += 1
            next[i] = j

    def repeatedSubstringPattern(self, s: str) -> bool:
        if len(s) == 0: return False
        next = [0] * len(s)
        self.get_next(next, s)
        # next[len(s) - 1] 為最長相等前後綴的長度
        # 用字串長度減去則代表一個周期的長度
        if next[-1] != 0 and len(s) % (len(s) - next[-1]) == 0:
            return True
        return False

def main():
    for line in stdin:
        s = line.strip()
        print(Solution().repeatedSubstringPattern(s))

if __name__ == '__main__':
    main()