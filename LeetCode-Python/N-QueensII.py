class Solution:
    def totalNQueens(self, n: int) -> int:
        def backtrack(row: int, diagonals: set, anti_diagonals: set, cols: set) -> int:
            if row == n:
                return 1  # Tüm satırlara başarıyla yerleştirildi

            count = 0
            for col in range(n):
                curr_diag = row - col
                curr_anti_diag = row + col

                # Eğer bu sütun veya çaprazlar zaten doluysa atla
                if col in cols or curr_diag in diagonals or curr_anti_diag in anti_diagonals:
                    continue

                # Veziri yerleştir
                cols.add(col)
                diagonals.add(curr_diag)
                anti_diagonals.add(curr_anti_diag)

                # Bir sonraki satıra geç
                count += backtrack(row + 1, diagonals, anti_diagonals, cols)

                # Geri al (backtrack)
                cols.remove(col)
                diagonals.remove(curr_diag)
                anti_diagonals.remove(curr_anti_diag)

            return count

        return backtrack(0, set(), set(), set())
