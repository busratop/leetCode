class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        # Karekök 1 ile x arasında bir değer olacaktır.
        # Arama alanını tanımlayalım:
        left, right = 1, x
        ans = 0 # Bulunan en büyük tamsayı karekökünü saklamak için

        while left <= right:
            mid = left + (right - left) // 2 # Taşmayı önlemek için bu şekilde hesaplanır
            
            # mid'in karesi x ile karşılaştırılır
            if mid * mid == x:
                return mid # Tam karekök bulundu
            elif mid * mid < x:
                # mid'in karesi x'ten küçükse, mid bir cevap olabilir
                # ve daha büyük bir değer aramak için sağ tarafa gideriz.
                ans = mid 
                left = mid + 1
            else: # mid * mid > x
                # mid'in karesi x'ten büyükse, mid çok büyüktür
                # daha küçük bir değer aramak için sol tarafa gideriz.
                right = mid - 1
        
        # Döngü bittiğinde 'ans', x'in tamsayı karekökünün en büyük değerini tutar.
        return ans
