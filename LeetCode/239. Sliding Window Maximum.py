from sys import stdin
from typing import List

class MyQueue:
    def __init__(self):
        self.queue = []

    def pop(self, value):
        # 比較要離開窗口的元素是否等於佇列出口的值，如果是就彈出
        if self.queue and self.queue[0] == value:
            self.queue.pop(0)

    def push(self, value):
        # 如果 push 的值大於佇列入口的值，就將佇列末端的值彈出，直到小於佇列入口
        while self.queue and value > self.queue[-1]:
            self.queue.pop()
        self.queue.append(value)
    def front(self):
        return self.queue[0]

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = MyQueue()
        result = []
        # 將前 k 個值 push
        for i in range(k):
            queue.push(nums[i])
        result.append(queue.front())        # 紀錄當前窗口內的最大值
        for i in range(k, len(nums)):
            queue.pop(nums[i - k])          # 移除窗口最前面的元素
            queue.push(nums[i])         # 新增最後加入窗口的元素
            result.append(queue.front())
        return result

def main():
    for line in stdin:
        nums = list(map(int, line.split()))
        k = int(stdin.readline())
        print(Solution().maxSlidingWindow(nums, k))

if __name__ == '__main__':
    main()