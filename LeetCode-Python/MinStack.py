class MinStack:

    def __init__(self):
        self.data_stack = []  # Stack to store actual elements
        self.min_stack = []   # Stack to store minimum elements

    def push(self, val: int) -> None:
        self.data_stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        if self.data_stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.data_stack.pop()

    def top(self) -> int:
        return self.data_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
