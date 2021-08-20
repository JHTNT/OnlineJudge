from sys import stdin

class Node:
    def __init__(self, val=None):
        self.val = val
        self.next = None

class MyLinkedList:
    def __init__(self):
        self._head = Node() # 建立虛擬首節點
        self._count = 0 # 節點數

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if 0 <= index < self._count:
            node = self._head
            for _ in range(index + 1): # 因為有虛擬首節點所以 + 1
                node = node.next
            return node.val
        else:
            return -1 # 無結果

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.addAtIndex(0, val)

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self.addAtIndex(self._count, val)

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index > self._count: return
        add_node = Node(val)
        previous_node, current_node = None, self._head
        for _ in range(index + 1):
            previous_node, current_node = current_node, current_node.next # 移動到指定節點並記錄前一個節點
        previous_node.next, add_node.next = add_node, current_node # 插入節點
        self._count += 1

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """ 
        if 0 <= index < self._count:
            previous_node, current_node = None, self._head
            for _ in range(index + 1):
                previous_node, current_node = current_node, current_node.next
            previous_node.next, current_node.next = current_node.next, None # 移除節點
            self._count -= 1

def main():
    for line in stdin:
        command = list(line.strip("\"\n").split("\",\""))
        value = eval(stdin.readline().strip())
        print(command, value)
        result = []
        for i, c in enumerate(command):
            if c == "MyLinkedList":
                linked_list = MyLinkedList()
                result.append(None)
            elif c == "get":
                result.append(linked_list.get(value[i][0]))
            elif c == "addAtHead":
                linked_list.addAtHead(value[i][0])
                result.append(None)
            elif c == "addAtTail":
                linked_list.addAtTail(value[i][0])
                result.append(None)
            elif c == "addAtIndex":
                linked_list.addAtIndex(value[i][0], value[i][1])
                result.append(None)
            elif c == "deleteAtIndex":
                linked_list.deleteAtIndex(value[i][0])
                result.append(None)
        print(result)

if __name__ == '__main__':
    main()