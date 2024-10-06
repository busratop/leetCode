class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = {'+': lambda x, y: x + y,
                    '-': lambda x, y: x - y,
                    '*': lambda x, y: x * y,
                    '/': lambda x, y: int(x / y)}  # Division truncates toward zero

        for token in tokens:
            if token not in operators:
                stack.append(int(token))
            else:
                operand2 = stack.pop()
                operand1 = stack.pop()
                operation = operators[token]
                result = operation(operand1, operand2)
                stack.append(result)

        return stack[0]
