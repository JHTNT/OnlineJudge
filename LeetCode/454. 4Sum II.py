from sys import stdin
from typing import List

class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int],
                     nums3: List[int], nums4: List[int]) -> int:
        count = 0
        a_plus_b = {}       # 紀錄 a + b 的所有組合及次數
        for i in nums1:
            for j in nums2:
                if i + j in a_plus_b:
                    a_plus_b[i + j] += 1
                else:
                    a_plus_b[i + j] = 1
        for i in nums3:
            for j in nums4:
                if -(i + j) in a_plus_b:        # 若 -(c + d) 存在就加入 count
                    count += a_plus_b[-(i + j)]
        return count

def main():
    for line in stdin:
        nums1 = list(map(int, line.split()))
        nums2 = list(map(int, stdin.readline().split()))
        nums3 = list(map(int, stdin.readline().split()))
        nums4 = list(map(int, stdin.readline().split()))
        print(Solution().fourSumCount(nums1, nums2, nums3, nums4))

if __name__ == '__main__':
    main()
