from typing import List

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        def traversal(root: TreeNode):
            if root == None: return
            result.append(root.val)         # 前序
            traversal(root.left)
            traversal(root.right)
        
        traversal(root)
        return result

def main():
    pass        # 無序樹狀結構不會做    

if __name__ == '__main__':
    main()