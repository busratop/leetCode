# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Base case: if root is None or if root is one of p or q 
        if root is None or root == p or root == q: 
            return root 
        # Recursively search in the left and right subtrees 
        left = self.lowestCommonAncestor(root.left, p, q) 
        right = self.lowestCommonAncestor(root.right, p, q) 
        # If both left and right are non-None, it means p and q are found in different branches
        # so root is their lowest common ancestor
        if left and right: 
            return root # Otherwise, return the non-None value 
        return left if left else right
