from sys import stdin
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()         # 原地排序
        n = len(nums)
        for i in range(n):
            # 使用雙指標法
            left = i + 1
            right = n - 1
            if nums[i] > 0:         # 若三個數中最小的已經大於 0，則無法湊出答案
                break
            if i > 0 and nums[i] == nums[i - 1]:        # 跳過重複的答案
                continue
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total > 0:       # right 左移使下次結果變小
                    right -= 1
                elif total < 0:     # left 右移使下次結果變大
                    left += 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    # 跳過重複的答案
                    while left != right and nums[left] == nums[left + 1]: left += 1
                    while left != right and nums[right] == nums[right - 1]: right -= 1
                    # 將指標範圍收縮
                    left += 1
                    right -= 1
        return result

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        print(Solution().threeSum(nums))

if __name__ == '__main__':
    main()