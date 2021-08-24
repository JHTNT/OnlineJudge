from sys import stdin

class ListNode:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        length_a, length_b = 0, 0
        current_a, current_b = headA, headB
        while current_a != None:
            length_a += 1
            current_a = current_a.next
        while current_b != None:
            length_b += 1
            current_b = current_b.next
        current_a, current_b = headA, headB
        if length_b > length_a:
            length_a, length_b = length_b, length_a
            current_a, current_b = current_b, current_a
        diff = length_a - length_b
        for _ in range(diff):
            current_a = current_a.next
        while current_a != None:
            if current_a == current_b:
                return current_a
            else:
                current_a = current_a.next
                current_b = current_b.next
        return None

def main(): # 測資特殊不好模擬
    pass

if __name__ == '__main__':
    main()