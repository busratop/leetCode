# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = float('-inf')
        self.maxPathDown(root)
        return self.max_sum

    def maxPathDown(self, node: TreeNode) -> int:
        if not node:
            return 0
        # Sol ve sağ alt ağaçlardaki maksimum yolu hesapla
        left = max(0, self.maxPathDown(node.left))
        right = max(0, self.maxPathDown(node.right))
        # Bu düğümden geçen maksimum yolu güncelle
        self.max_sum = max(self.max_sum, left + right + node.val)
        # Bu düğümden başlayarak tek bir dalı içeren maksimum yolu döndür
        return max(left, right) + node.val
