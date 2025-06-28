class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        if not board or not board[0]:
            return

        rows, cols = len(board), len(board[0])

        def dfs(r, c):
            # Sınır dışı ya da 'O' olmayan hücreyi geç
            if r < 0 or r >= rows or c < 0 or c >= cols or board[r][c] != 'O':
                return
            board[r][c] = 'T'  # Geçici olarak işaretle
            # Dört yöne git
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)

        # 1. Kenar hücrelerdeki tüm 'O' hücreler için DFS başlat
        for i in range(rows):
            dfs(i, 0)            # sol kenar
            dfs(i, cols - 1)     # sağ kenar
        for j in range(cols):
            dfs(0, j)            # üst kenar
            dfs(rows - 1, j)     # alt kenar
