# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = 0 
        result = None 
        def inorderTraversal(node): 
            nonlocal count, result 
            if not node or result is not None: 
                return 
            inorderTraversal(node.left) 
            count += 1 
            if count == k: 
                result = node.val 
                return 
            inorderTraversal(node.right) 
        inorderTraversal(root) 
        return result
