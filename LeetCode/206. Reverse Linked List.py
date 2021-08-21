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
        if self.head == None: # head 為 None 代表串列是空的
            self.head = new_node
            self.tail = new_node
        else: # 將 tail.next 設為 new_node，tail 就會指向 new_node
            self.tail.next = new_node
            self.tail = self.tail.next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        previous, current = None, head
        while current != None:
            current.next, temp = previous, current.next # 將原本的 current.next 暫存
            previous, current = current, temp # 將 current.next 反向連接並移到下一個節點
        return previous

def main():
    for line in stdin:
        nodes = list(map(int, line.split()))
        head = SingleLinkedList()
        for i in nodes:
            head.append(i)
        print(Solution().reverseList(head.head))

if __name__ == '__main__':
    main()