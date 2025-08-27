class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)

        def get_position(s):
            quot, rem = divmod(s - 1, n)
            row = n - 1 - quot
            col = rem if quot % 2 == 0 else n - 1 - rem
            return row, col

        visited = [False] * (n * n + 1)
        queue = deque()
        queue.append((1, 0))  # (current square, move count)
        visited[1] = True

        while queue:
            square, moves = queue.popleft()

            if square == n * n:
                return moves

            for i in range(1, 7):
                next_square = square + i
                if next_square > n * n:
                    continue

                r, c = get_position(next_square)

                # Go to destination of snake or ladder
                if board[r][c] != -1:
                    next_square = board[r][c]

                if not visited[next_square]:
                    visited[next_square] = True
                    queue.append((next_square, moves + 1))

        return -1  # Not reachable
