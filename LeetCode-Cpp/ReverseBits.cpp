class Solution {
public:
    int reverseBits(int n) {
                // İşlemleri unsigned int üzerinde yapmak, bit manipülasyonu için daha güvenlidir,
        // çünkü int'in işaret biti ve sağa kaydırma davranışı platforma göre değişebilir.
        unsigned int num = (unsigned int)n;
        unsigned int result = 0;

        // 32 bitin her birini tek tek işleriz
        for (int i = 0; i < 32; ++i) {
            // Sonucu bir bit sola kaydırarak yeni bit için yer açarız
            result <<= 1;
            // num'ın en sağdaki bitini (LSB - Least Significant Bit) alırız
            // ve bunu sonucun en sağdaki yerine ekleriz
            result |= (num & 1);
            // num'ı bir bit sağa kaydırarak bir sonraki bit için hazırlanırız
            num >>= 1;
        }

        // Sonucu tekrar int'e dönüştürerek döndürürüz
        return (int)result;
    }
};
