from sys import stdin

class Solution:
    def isHappy(self, n: int) -> bool:
        temp = set() # 儲存出現過的結果
        while True:
            sum_ = self.get_sum(n)
            if sum_ == 1:
                return True
            elif sum_ in temp: # 如果與之前的結果相同代表陷入循環
                return False
            else:
                temp.add(sum_)
                n = sum_

    def get_sum(self, n):
        sum_ = 0
        while n > 0:
            sum_ += (n % 10) ** 2
            n //= 10
        return sum_

def main():
    for line in stdin:
        n = int(line)
        print(Solution().isHappy(n))

if __name__ == '__main__':
    main()