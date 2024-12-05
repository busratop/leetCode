# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # Kök düğüm boşsa, ağaç simetriktir 
        if root is None: 
            return True 
        # Yardımcı fonksiyonu çağır 
        return self.isMirror(root.left, root.right) 
    def isMirror(self, t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool: 
            # Her iki düğüm de boşsa, aynıdırlar 
            if t1 is None and t2 is None: 
                return True 
            # Biri boş, diğeri değilse, farklıdırlar 
            if t1 is None or t2 is None: 
                return False 
            # Düğüm değerleri farklıysa, farklıdırlar 
            if t1.val != t2.val: 
                return False 
            # Simetrik olup olmadığını kontrol et 
            return self.isMirror(t1.right, t2.left) and self.isMirror(t1.left, t2.right)
