# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: 
            return [] 
        result = [] 
        nodeDeque = deque([root]) 
        leftToRight = True 
        while nodeDeque: 
            level = [] 
            size = len(nodeDeque) 
            for _ in range(size): 
                if leftToRight: 
                    node = nodeDeque.popleft() 
                    level.append(node.val) 
                    if node.left: 
                        nodeDeque.append(node.left) 
                    if node.right: 
                        nodeDeque.append(node.right)
                else: 
                    node = nodeDeque.pop() 
                    level.append(node.val) 
                    if node.right: 
                        nodeDeque.appendleft(node.right) 
                    if node.left: 
                        nodeDeque.appendleft(node.left) 
            result.append(level)
            leftToRight = not leftToRight 
        return result
