from sys import stdin

class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        for i in range(0, len(s), 2 * k):
            s[i:i + k] = reversed(s[i:i + k])
        return "".join(s)

def main():
    for line in stdin:
        s = line.strip()
        k = int(stdin.readline())
        print(Solution().reverseStr(s, k))

if __name__ == '__main__':
    main()