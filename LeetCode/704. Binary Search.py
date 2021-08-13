from sys import stdin
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1 # 定義左右閉區間

        while left <= right: # left == right 依然有效
            middle = (left + right) // 2 # 取得區間中央的位置

            if nums[middle] < target: # 目標值在右區間
                left = middle + 1
            elif nums[middle] > target: # 目標值在左區間
                right = middle - 1
            else: # nums[middle] == target
                return middle
        return -1 # 找不到目標值

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        target = int(stdin.readline())

        print(Solution().search(nums, target))

if __name__ == '__main__':
    main()

# http://programmercarl.com/0704.二分查找.html