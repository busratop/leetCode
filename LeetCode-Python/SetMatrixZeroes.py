class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])

        # Variables to check if the first row and column need to be set to zeros
        first_row_zero = False
        first_col_zero = False

        # Check if the first row needs to be set to zeros
        for j in range(n):
            if matrix[0][j] == 0:
                first_row_zero = True
                break

        # Check if the first column needs to be set to zeros
        for i in range(m):
            if matrix[i][0] == 0:
                first_col_zero = True
                break

        # Mark the rows and columns that need to be set to zeros
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0  # Marking the first element of the row
                    matrix[0][j] = 0  # Marking the first element of the column

        # Set zeros based on the marked rows and columns
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # Set the first row and column to zeros if needed
        if first_row_zero:
            matrix[0] = [0] * n

        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0

        
