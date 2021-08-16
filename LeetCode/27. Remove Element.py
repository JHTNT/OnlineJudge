from sys import stdin
from typing import List

class Solution: # O(n)
    def removeElement(self, nums: List[int], val: int) -> int:   
        i, n = 0, len(nums)
        for j in range(n): # 使用雙指標法
            if nums[j] != val: # 若相同則陣列往前移一位
                nums[i] = nums[j]
                i += 1
        return i

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        val = int(stdin.readable())
        n = Solution().removeElement(nums, val)
        print(nums[:n])

if __name__ == '__main__':
    main()