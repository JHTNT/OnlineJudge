from sys import stdin
from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        if n == 0: return [-1, -1] # 空陣列直接回傳
        def find(find_left):
            left, right = 0, n - 1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] < target:
                    left = mid + 1
                elif nums[mid] > target:
                    right = mid - 1
                else: # 找到任意一個 target 之後開始判斷
                    if find_left: # 尋找左邊界
                        if mid > 0 and nums[mid] == nums[mid - 1]: # 如果不是最左邊則往左逼近
                            right = mid - 1
                        else: return mid
                    else: # 同理尋找右邊界
                        if mid < n - 1 and nums[mid] == nums[mid + 1]:
                            left = mid + 1
                        else: return mid
            return -1 # 找不到 target
        return [find(True), find(False)]

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        target = int(stdin.readline())
        print(Solution().searchRange(nums, target))

if __name__ == '__main__':
    main()