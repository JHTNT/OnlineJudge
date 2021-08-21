from sys import stdin

class Solution:
    def mySqrt(self, x: int) -> int:
        left, right = 1, x // 2 + 1 # 平方根必在 x / 2 + 1 內，可以減少搜索範圍
        while left <= right:
            mid = (left + right) // 2
            temp = x // mid
            if temp > mid:
                left = mid + 1
            elif temp < mid:
                right = mid - 1
            else:
                return mid
        return right # 結束時 left = right + 1，平方根在兩者之間，且需要向下取整，所以取 right

def main():
    for line in stdin:
        x = int(line)
        print(Solution().mySqrt(x))

if __name__ == '__main__':
    main()