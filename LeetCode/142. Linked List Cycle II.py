class ListNode:
    def __init__(self, val=None):
        self.val = val
        self.next = None

class Solution: # 詳細邏輯參考文章
    def detectCycle(self, head: ListNode) -> ListNode:
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next # fast 一次移動兩格
            slow = slow.next # slow 一次移動一格
            if fast == slow: # 兩指標相遇時必在循環內
                m, n = head, slow # 在首節點與相遇處建立指標
                while m != n: # m 與 n 相遇時必在循環入口
                    m = m.next
                    n = n.next
                return m 
        return None

def main(): # 省略測資
    pass

if __name__ == '__main__':
    main()

# https://programmercarl.com/0142.环形链表II.html