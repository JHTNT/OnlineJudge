from sys import stdin
from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        square = [None] * n
        i, j, k = 0, n - 1, n - 1 # 使用雙指標法
        while i <= j: # 指標重合時計算最後一次
            left = nums[i] ** 2
            right = nums[j] ** 2
            if left > right: # 將兩個指標中平方後較大的數存入
                square[k] = left
                i += 1 # 指標由兩側向中間接近
            else:
                square[k] = right
                j -= 1
            k -= 1
        return square

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        print(Solution().sortedSquares(nums))

if __name__ == '__main__':
    main()