from sys import stdin
from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # 用雙指標交換兩端的字元
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

def main():
    for line in stdin:
        s = list(line.strip())
        Solution().reverseString(s)
        print(s)

if __name__ == '__main__':
    main()