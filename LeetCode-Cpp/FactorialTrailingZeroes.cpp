class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // Sayılar 5'in katı olduğunda bir tane 5 çarpanı ekleriz.
        // Sayılar 25'in katı olduğunda iki tane 5 çarpanı ekleriz (çünkü 25 = 5 * 5).
        // Sayılar 125'in katı olduğunda üç tane 5 çarpanı ekleriz (çünkü 125 = 5 * 5 * 5).
        // Ve bu böyle devam eder.
        // Bu yüzden, n'i 5'e, 25'e, 125'e vb. bölerek her birinden gelen 5 çarpanlarını toplarız.
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};
