class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        rows, cols = len(board), len(board[0])
        next_board = [[0] * cols for _ in range(rows)]

        def count_live_neighbors(row, col):
            count = 0
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]

            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                if 0 <= new_row < rows and 0 <= new_col < cols and board[new_row][new_col] == 1:
                    count += 1

            return count

        for row in range(rows):
            for col in range(cols):
                live_neighbors = count_live_neighbors(row, col)

                if board[row][col] == 1:  # Live cell
                    if live_neighbors < 2 or live_neighbors > 3:
                        next_board[row][col] = 0  # Dies due to under-population or over-population
                    else:
                        next_board[row][col] = 1  # Lives on to the next generation

                else:  # Dead cell
                    if live_neighbors == 3:
                        next_board[row][col] = 1  # Becomes a live cell due to reproduction

        for row in range(rows):
            for col in range(cols):
                board[row][col] = next_board[row][col]
            
