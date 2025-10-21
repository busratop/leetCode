class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // dp[i][j] = word1'in ilk i karakterini, word2'nin ilk j karakterine dönüştürmek için gereken minimum işlem sayısı
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // İlk satır ve sütun: boş kelimeye dönüşüm maliyeti
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
        
        // DP tablosunu doldur
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // harfler eşitse işlem gerekmez
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // silme
                        dp[i][j - 1],    // ekleme
                        dp[i - 1][j - 1] // değiştirme
                    });
                }
            }
        }
        
        return dp[m][n];

    }
};
