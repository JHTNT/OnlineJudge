from sys import stdin

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 0, num // 2 + 1 # 在確保平方根在範圍中的情況下縮小範圍
        while left <= right:
            mid = (left + right) // 2
            temp = mid ** 2
            if temp < num:
                left = mid + 1
            elif temp > num:
                right = mid - 1
            else:
                return True
        return False

def main():
    for line in stdin:
        num = int(line)
        print(Solution().isPerfectSquare(num))

if __name__ == '__main__':
    main()