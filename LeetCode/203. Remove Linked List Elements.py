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
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy_head = ListNode(next=head) # 建立虛擬首節點並指向 head
        current = dummy_head
        while current.next != None:
            if current.next.val == val:
                current.next = current.next.next # 跳過值為 val 的節點
            else:
                current = current.next
        return dummy_head.next

def main():
    for line in stdin:
        nodes = list(map(int, line.split()))
        val = int(stdin.readline())
        head = SingleLinkedList()
        for i in nodes:
            head.append(i)
        print(Solution().removeElements(head.head, val))

if __name__ == '__main__':
    main()