class Solution:
    def isPalindrome(self, x: int) -> bool:
         # Negatif sayılar palindrom olamaz.
        if x < 0:
            return False

        # Sayı 0 dışında bir sayı ise ve 0 ile bitiyorsa palindrom olamaz.
        # Örneğin, 10, 100 gibi sayılar 0 ile bittiği için tersten okunduğunda farklıdır (01, 001).
        # 0 sayısı özel bir durumdur, o bir palindromdur.
        if x % 10 == 0 and x != 0:
            return False

        reverted_number = 0
        # Sayının yarısını ters çeviriyoruz.
        # Örneğin, 12321 için loop 3 kez döner:
        # 1. iterasyon: reverted_number = 1, x = 1232
        # 2. iterasyon: reverted_number = 12, x = 123
        # 3. iterasyon: reverted_number = 123, x = 12 (artık x <= reverted_number)
        # Bu durumda, sayının ortasındaki basamağı atlayabiliriz.
        while x > reverted_number:
            reverted_number = reverted_number * 10 + x % 10
            x //= 10  # Tam sayı bölme

        # Eğer sayı çift haneli ise (örneğin 1221), x ve reverted_number eşit olmalı (12 == 12).
        # Eğer sayı tek haneli ise (örneğin 12321), ortadaki basamağı atlamamız gerekir.
        # x = 12 ve reverted_number = 123 olduğunda, reverted_number'ın son basamağını atarız (123 // 10 = 12).
        return x == reverted_number or x == reverted_number // 10
