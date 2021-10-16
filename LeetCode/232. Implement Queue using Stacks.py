from sys import stdin

class MyQueue:
    def __init__(self):
        # 用兩個堆疊模擬佇列操作（先進先出）
        self.stack_in = []
        self.stack_out = []

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        if self.empty():
            return None
        
        if self.stack_out:
            return self.stack_out.pop()
        else:
            for _ in range(len(self.stack_in)):
                self.stack_out.append(self.stack_in.pop())
            return self.stack_out.pop()

    def peek(self) -> int:
        ans = self.pop()
        self.stack_out.append(ans)
        return ans

    def empty(self) -> bool:
        return not (self.stack_in or self.stack_out)

def main():
    for line in stdin:
        command = line.split()
        value = list(map(int, stdin.readline().split()))
        for c, i in enumerate(command):
            if i == "MyQueue":
                queue = MyQueue()
            elif i == "push":
                queue.push(value[c])
            elif i == "pop":
                print(queue.pop())
            elif i == "peek":
                print(queue.peek())
            elif i == "empty":
                print(queue.empty())

if __name__ == '__main__':
    main()