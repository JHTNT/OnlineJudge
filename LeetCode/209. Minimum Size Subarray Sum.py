from sys import stdin
from typing import List

class Solution: # O(n)
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        result = float("INF") # 建立一個無限大的數
        S, index = 0, 0
        for i in range(len(nums)):
            S += nums[i]
            while S >= target: # 如果值超過 target 就移動指針並檢查
                result = min(result, i - index + 1) # 若長度更小就更新
                S -= nums[index]
                index += 1
        return 0 if result == float("INF") else result # 如果沒有符合的子陣列就回傳 0

def main():
    for line in stdin:
        target = int(line)
        nums = list(map(int, stdin.readline().split()))
        print(Solution().minSubArrayLen(target, nums))

if __name__ == '__main__':
    main()