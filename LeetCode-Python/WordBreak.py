class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
         # Kelime sözlüğünü hızlı aramalar için bir set'e dönüştür
        word_set = set(wordDict)
        
        n = len(s)
        # dp[i], s'nin ilk i karakterinin (s[0:i]) sözlükteki kelimelerle bölünüp bölünemeyeceğini gösterir.
        dp = [False] * (n + 1)
        
        # Boş string her zaman bölünebilir.
        dp[0] = True
        
        # Her bir uzunluk için kontrol et
        for i in range(1, n + 1):
            # String'in her olası bölüm noktasını kontrol et (j)
            for j in range(i):
                # Eğer dp[j] doğruysa (s[0:j] bölünebilir)
                # VE s[j:i] alt string'i sözlükte varsa, o zaman dp[i] doğrudur.
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break # s[0:i] için bir segmentasyon bulduk, daha fazla kontrol etmeye gerek yok.
                    
        # s'nin tamamının (ilk n karakterinin) bölünüp bölünemediğini döndür.
        return dp[n]
