from sys import stdin

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        temp = [0] * 26
        asc = ord("a") # 獲取 a 的 ascii
        for i in s:
            temp[ord(i) - asc] += 1 # 利用 ascii 的差來記錄出現次數
        for i in t:
            temp[ord(i) - asc] -= 1
        for i in temp:
            if i != 0: # 若任意一個不為 0 表示有字母不同
                return False
        return True

def main():
    for line in stdin:
        s = line.strip()
        t = stdin.readline().strip()
        print(Solution().isAnagram(s, t))

if __name__ == '__main__':
    main()