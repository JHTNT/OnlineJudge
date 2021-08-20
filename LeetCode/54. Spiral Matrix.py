from sys import stdin
from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix[0]), len(matrix)
        right, bottom, left, top = n, m, 0, 0
        num = []
        while left < right and top < bottom:
            for i in range(left, right):
                num.append(matrix[top][i])
            top += 1
            for j in range(top, bottom):
                num.append(matrix[j][right - 1])
            right -= 1
            if left < right and top < bottom: # 避免在迴圈內結束後再往回判斷
                for i in range(right - 1, left - 1, -1):
                    num.append(matrix[bottom - 1][i])
                bottom -= 1
                for j in range(bottom - 1, top - 1, -1):
                    num.append(matrix[j][left])
                left += 1
        return num

def main():
    for line in stdin:
        matrix = eval(line)
        print(Solution().spiralOrder(matrix))

if __name__ == '__main__':
    main()