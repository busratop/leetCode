class Solution {
public:
    bool isPalindrome(int x) {
        // Negatif sayılar palindrom olamaz.
        if (x < 0) {
            return false;
        }

        // Sayı 0 dışında bir sayı ise ve 0 ile bitiyorsa palindrom olamaz.
        // Örneğin, 10, 100 gibi sayılar 0 ile bittiği için tersten okunduğunda farklıdır (01, 001).
        // 0 sayısı özel bir durumdur, o bir palindromdur.
        if (x % 10 == 0 && x != 0) {
            return false;
        }

        int revertedNumber = 0;
        // Sayının yarısını ters çeviriyoruz.
        // Örneğin, 12321 için loop 3 kez döner:
        // 1. iterasyon: revertedNumber = 1, x = 1232
        // 2. iterasyon: revertedNumber = 12, x = 123
        // 3. iterasyon: revertedNumber = 123, x = 12 (artık x <= revertedNumber)
        // Bu durumda, sayının ortasındaki basamağı atlayabiliriz.
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // Eğer sayı çift haneli ise (örneğin 1221), x ve revertedNumber eşit olmalı (12 == 12).
        // Eğer sayı tek haneli ise (örneğin 12321), ortadaki basamağı atlamamız gerekir.
        // x = 12 ve revertedNumber = 123 olduğunda, revertedNumber'ın son basamağını atarız (123 / 10 = 12).
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
