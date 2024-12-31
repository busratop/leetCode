# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = [] 
        if not root: 
            return result 
        # Kullanılacak olan kuyruk veriyapısı 
        queue = [root] 
        while queue: 
            level_size = len(queue) 
            for i in range(level_size): 
                node = queue.pop(0) 
                # Sağdan bakıldığında bu seviyede görünecek düğümü ekle 
                if i == level_size - 1: 
                    result.append(node.val) 
                # Sol ve sağ alt ağaçları sıraya ekle 
                if node.left: 
                    queue.append(node.left) 
                if node.right: 
                    queue.append(node.right) 
        return result
