from sys import stdin
from typing import List

class Solution: # 思路與 zerojudge a417 相同
    def generateMatrix(self, n: int) -> List[List[int]]:
        right, bottom, left, top = n - 1, n - 1, -1, 0
        num = [[0] * n for _ in range(n)]
        count, max = 0, n * n
        while count < max:
            left += 1
            for i in range(left, right + 1):
                count += 1
                num[top][i] = count
            top += 1
            for j in range(top, bottom + 1):
                count += 1
                num[j][right] = count
            right -= 1
            for i in range(right, left - 1, -1):
                count += 1
                num[bottom][i] = count
            bottom -= 1
            for j in range(bottom, top - 1, -1):
                count += 1
                num[j][left] = count
        return num

def main():
    for line in stdin:
        n = int(line)
        print(Solution().generateMatrix(n))

if __name__ == '__main__':
    main()