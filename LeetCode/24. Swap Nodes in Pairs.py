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
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy_head = ListNode(next=head)
        current = dummy_head
        while current.next and current.next.next:
            temp1 = current.next # 儲存交換前的指標
            temp2 = current.next.next.next
            current.next = current.next.next
            current.next.next = temp1 # 連接到正確的位置
            current.next.next.next = temp2
            current = current.next.next # 移到下一次循環的起始位置
        return dummy_head.next

def main():
    for line in stdin:
        nodes = list(map(int, line.split()))
        head = SingleLinkedList()
        for i in nodes:
            head.append(i)
        print(Solution().swapPairs(head.head))

if __name__ == '__main__':
    main()