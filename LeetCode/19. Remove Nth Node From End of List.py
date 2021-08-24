from sys import stdin

class ListNode:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        current_node = self
        chain = []
        while current_node != None:
            chain.append(current_node.val)
            current_node = current_node.next
        return str(chain)

class SingleLinkedList():
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, val):
        new_node = ListNode(val)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = self.tail.next

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy_head = ListNode(next=head)
        slow, fast = dummy_head, dummy_head
        for _ in range(n): # fast 指標先往前走 n 步
            fast = fast.next
        while fast.next != None: # 走到尾端時，slow.next 就是倒數第 n 個
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy_head.next

def main():
    for line in stdin:
        nodes = list(map(int, line.split()))
        n = int(stdin.readline())
        head = SingleLinkedList()
        for i in nodes:
            head.append(i)
        print(Solution().removeNthFromEnd(head.head, n))

if __name__ == '__main__':
    main()