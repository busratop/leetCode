class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
    
        while matrix:
            # Traverse right
            result += matrix.pop(0)
            
            if matrix and matrix[0]:
                # Traverse down
                for row in matrix:
                    result.append(row.pop())
                    
            if matrix:
                # Traverse left
                result += matrix.pop()[::-1]
                
            if matrix and matrix[0]:
                # Traverse up
                for row in matrix[::-1]:
                    result.append(row.pop(0))
                
        return result
