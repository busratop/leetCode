# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        # Düğümler arasındaki farkları bulmak için bir liste 
        vals = [] 
        # Ağacı sıralı dolaşan yardımcı fonksiyon 
        def inorder(node): 
            if node: 
                inorder(node.left) 
                vals.append(node.val) 
                inorder(node.right) 
        # Ağacı sıralı dolaşarak düğüm değerlerini vals listesine ekliyoruz 
        inorder(root) 
        # Minimum farkı bulmak için varsayılan büyük bir değerle başlıyoruz 
        min_diff = float('inf') 
        # Sıralı değerler arasındaki farkları hesaplayarak minimum olanı buluyoruz 
        for i in range(1, len(vals)): 
            min_diff = min(min_diff, vals[i] - vals[i - 1]) 
        return min_diff
