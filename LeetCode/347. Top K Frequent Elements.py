from sys import stdin
from typing import List
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}          # 計算出現次數
        for i in range(len(nums)):
            count[nums[i]] = count.get(nums[i], 0) + 1

        min_heap = []       # 最小堆積，大小為 k
        for key, freq in count.items():
            heapq.heappush(min_heap, (freq, key))
            # 若堆積大小超過 k 就彈出，保持大小為 k
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        result = [0] * k
        # 因為最小堆疊彈出的是最小的，所以要反過來放
        for i in range(k):
            result[k - i - 1] = heapq.heappop(min_heap)[1]
        return result

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        k = int(stdin.readline())
        print(Solution().topKFrequent(nums, k))

if __name__ == '__main__':
    main()