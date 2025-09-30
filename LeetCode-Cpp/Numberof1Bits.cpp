class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        // `unsigned int`'e dönüştürmek, özellikle negatif sayılarda sağa kaydırma
        // ve bit işlemleri sırasında beklenen davranışı sağlamak için önemlidir.
        // Bu, `n`'yi 32 bitlik bir bit deseni olarak ele almamızı sağlar.
        unsigned int num = n; 
        
        while (num != 0) {
            num &= (num - 1); // En düşük anlamlı 1 bitini temizler (Brian Kernighan algoritması)
            count++;
        }
        return count;
    }
};
