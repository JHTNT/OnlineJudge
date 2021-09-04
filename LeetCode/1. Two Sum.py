from sys import stdin
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}       # 儲存檢查過的數字與其 index
        for i, num in enumerate(nums):
            j = hash_map.get(target - num)      # 搜尋 target - num 的值是否出現過
            if j is not None and i != j:        # 排除數字重複
                return sorted([i, j])
            hash_map[num] = i # 若沒有則將當前數字加入

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        target = int(stdin.readline())
        print(Solution().twoSum(nums, target))

if __name__ == '__main__':
    main()