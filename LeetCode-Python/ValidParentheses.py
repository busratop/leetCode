class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closing = {')': '(', ']': '[', '}': '{'}

        for char in s:
            if char in closing:
                if not stack or stack.pop() != closing[char]:
                    return False
            else:
                stack.append(char)

        return not stack
