# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None: 
            return None 
        # Sol ve sağ çocukları tersine çevir 
        left = self.invertTree(root.left) 
        right = self.invertTree(root.right) 
        # Sol ve sağ çocukları değiştir 
        root.left = right 
        root.right = left 
        return root
