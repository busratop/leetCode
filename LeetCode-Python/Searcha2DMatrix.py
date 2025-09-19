class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1

        while left <= right:
            mid = (left + right) // 2
            row, col = divmod(mid, n)   # satır ve sütun hesaplama
            midVal = matrix[row][col]

            if midVal == target:
                return True
            elif midVal < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
