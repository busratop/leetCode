# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # Eğer kök düğüm boşsa, derinlik 0'dır 
        if root is None: 
            return 0 
        # Sol ve sağ alt ağaçların derinliğini hesapla 
        left_depth = self.maxDepth(root.left) 
        right_depth = self.maxDepth(root.right) 
        # Daha büyük derinliği al ve 1 ekle 
        return max(left_depth, right_depth) + 1
