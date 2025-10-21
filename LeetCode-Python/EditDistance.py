
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # İlk satır ve sütun: boş kelimeye dönüşüm maliyeti
        for i in range(m + 1):
            dp[i][0] = i  # silme işlemleri
        for j in range(n + 1):
            dp[0][j] = j  # ekleme işlemleri

        # Dinamik programlama tablosunu doldur
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]  # harfler eşitse işlem gerekmez
                else:
                    dp[i][j] = 1 + min(
                        dp[i - 1][j],    # silme
                        dp[i][j - 1],    # ekleme
                        dp[i - 1][j - 1] # değiştirme
                    )

        return dp[m][n]
