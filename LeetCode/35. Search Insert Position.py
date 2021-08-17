from sys import stdin
from typing import List

class Solution: # O(logn)
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] < target:
                left = middle + 1
            elif nums[middle] > target:
                right = middle - 1
            else: return middle
        return left # 若 target 不在陣列中，左指標最後會跑到右指標右方，此時應將 target 插入 left 處

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        target = int(stdin.readline())
        print(Solution().searchInsert(nums, target))

if __name__ == '__main__':
    main()