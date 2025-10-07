class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            // Negatif sayılar için karekök tanımsızdır.
            // Problemin kısıtlamalarına göre genellikle x >= 0 kabul edilir.
            // Bu durumda 0 döndürülebilir veya hata fırlatılabilir.
            return 0; 
        }
        if (x == 0) {
            return 0;
        }

        // Karekök 1 ile x arasında bir değer olacaktır.
        // Ancak overflow'u önlemek için 'mid' değerini ve karesini long long yapalım.
        long long low = 1;
        long long high = x;
        long long ans = 0; // Bulunan en büyük tamsayı karekökünü saklamak için

        while (low <= high) {
            long long mid = low + (high - low) / 2; // Taşmayı önlemek için bu şekilde hesaplanır
            
            // mid*mid ifadesinin taşmasını önlemek için long long kullanıldı
            if (mid * mid == x) {
                return static_cast<int>(mid); // Tam karekök bulundu
            } else if (mid * mid < x) {
                // mid'in karesi x'ten küçükse, mid bir cevap olabilir
                // ve daha büyük bir değer aramak için sağ tarafa gideriz.
                ans = mid; 
                low = mid + 1;
            } else { // mid * mid > x
                // mid'in karesi x'ten büyükse, mid çok büyüktür
                // daha küçük bir değer aramak için sol tarafa gideriz.
                high = mid - 1;
            }
        }
        
        // Döngü bittiğinde 'ans', x'in tamsayı karekökünün en büyük değerini tutar.
        return static_cast<int>(ans);
    }
};
