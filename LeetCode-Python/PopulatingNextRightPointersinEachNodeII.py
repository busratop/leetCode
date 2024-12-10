"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: 
            return None 

        leftmost = root 

        while leftmost: 
            head = leftmost 
            prev, leftmost = None, None 

            while head: 
                # Sol çocuğu işle 
                if head.left: 
                    if prev: 
                        prev.next = head.left 
                    else: 
                        leftmost = head.left 
                    prev = head.left 
                # Sağ çocuğu işle 
                if head.right: 
                    if prev: 
                        prev.next = head.right 
                    else: 
                        leftmost = head.right 
                    prev = head.right 
                head = head.next 
        return root
