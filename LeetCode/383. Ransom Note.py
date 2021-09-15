from sys import stdin
from typing import List

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        count = [0] * 26
        for i in magazine:
            count[ord(i) - 97] += 1         # a 的 ascii 為 97
        for i in ransomNote:
            if count[ord(i) - 97] == 0:
                return False
            else:
                count[ord(i) - 97] -= 1
        return True


def main():
    for line in stdin:
        ransomNote = line.strip()
        magazine = stdin.readline().strip()
        print(Solution().canConstruct(ransomNote, magazine))

if __name__ == '__main__':
    main()