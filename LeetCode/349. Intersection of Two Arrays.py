from sys import stdin
from typing import List

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = set() # 資料不重複且不需要排序
        set1 = set(nums1)
        for i in nums2:
            if i in set1:
                result.add(i)
        return list(result)

def main():
    for line in stdin:
        nums1 = list(map(int, line.split()))
        nums2 = list(map(int, stdin.readline().split()))
        print(Solution().intersection(nums1, nums2))

if __name__ == '__main__':
    main()