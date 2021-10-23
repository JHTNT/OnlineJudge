from sys import stdin
from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for item in tokens:
            if item not in {"+", "-", "*", "/"}:
                stack.append(item)
            else:
                m, n = stack.pop(), stack.pop()
                stack.append(int(eval(f"{n}{item}{m}")))
        return int(stack.pop())

def main():
    for line in stdin:
        tokens = list(line.split())
        print(Solution().evalRPN(tokens))

if __name__ == '__main__':
    main()