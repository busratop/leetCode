class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
                // Sözlük kelimelerini hızlı arama için bir hash seti'ne kopyala
        std::unordered_set<std::string> dictSet(wordDict.begin(), wordDict.end());

        int n = s.length();
        // dp[i], s'nin ilk i karakterinin (s.substr(0, i)) sözlük kelimeleriyle segmentlere ayrılabildiğini gösterir.
        std::vector<bool> dp(n + 1, false);
        
        // Boş dizge her zaman segmentlere ayrılabilir.
        dp[0] = true;

        // Her bir uzunluk için kontrol et
        for (int i = 1; i <= n; ++i) {
            // Dizgenin her olası bölüm noktasını kontrol et
            for (int j = 0; j < i; ++j) {
                // Eğer dp[j] doğruysa (s'nin ilk j karakteri segmentlere ayrılabilir)
                // VE s[j...i-1] alt dizgesi sözlükte varsa, o zaman dp[i] doğrudur.
                if (dp[j] && dictSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // s[0...i-1] için bir segmentasyon bulduk, daha fazla kontrol etmeye gerek yok.
                }
            }
        }

        // s'nin tamamının (ilk n karakterinin) segmentlere ayrılıp ayrılamadığını döndür.
        return dp[n];
    }
};
