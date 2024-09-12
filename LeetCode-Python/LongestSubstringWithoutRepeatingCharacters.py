class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Fonksiyon, en uzun benzersiz alt dize uzunluğunu bulmaya çalışıyor.
        
        # Başlangıç indeksi, alt dizeyi oluştururken kullanılacak başlangıç pozisyonunu belirtir.
        start = 0
        
        # count, en uzun benzersiz alt dizenin uzunluğunu takip eden değişken.
        count = 0
        
        # s stringinin her bir karakterini ziyaret eden bir döngü.
        for end in range(1, len(s)+1):
            # s[start:end] ifadesi, şu anki alt dizeyi temsil eder.
            
            # Eğer alt dize içindeki karakterlerin sayısı, alt dizenin uzunluğuna eşitse,
            # bu durumda alt dize benzersizdir, çünkü her karakter sadece bir kez bulunur.
            if len(set(s[start:end])) == len(s[start:end]):
                # Eğer şu anki alt dize, şu ana kadar bulunan en uzun benzersiz alt dizeden daha uzunsa,
                # count'u güncelle.
                if (end - start + 1) > count:
                    count = len(s[start:end])
            else:
                # Eğer alt dize içinde tekrarlanan karakterler varsa, başlangıç indeksini bir artır.
                start += 1
        
        # En uzun benzersiz alt dize uzunluğunu döndür.
        return count
