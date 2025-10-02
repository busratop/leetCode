class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        
        # Bir 32-bitlik işaretli tamsayı için her bit pozisyonu üzerinde döngü yap (0'dan 31'e)
        for i in range(32):
            sum_bits = 0
            # Dizideki her sayıyı kontrol et
            for num in nums:
                # Sayının i'inci bitinin ayarlı (1) olup olmadığını kontrol et
                if (num >> i) & 1:
                    sum_bits += 1
            
            # Eğer bu bit pozisyonunun (i) toplamı 3'ün katı değilse (yani 1 kalıyorsa),
            # tek sayının bu bit pozisyonunda '1'e sahip olduğu anlamına gelir.
            if sum_bits % 3 == 1:
                # Sonucumuza bu biti ayarla
                result |= (1 << i)
        
        # Python'da tamsayılar keyfi boyutta olduğundan, 
        # eğer tek sayı negatifse, yukarıdaki döngü sonucunda `result` 
        # pozitif bir değer (örneğin, 32-bit ikinin tümleyeni gösteriminde) olarak görünebilir.
        # Eğer 31. bit (32-bit işaretli bir tamsayı için işaret biti) ayarlanmışsa,
        # bu, sonucun negatif bir sayı olması gerektiği anlamına gelir.
        # Bunu doğru negatif değere dönüştürmek için 2^32 çıkarırız.
        # Bu, `result` değeri 2^31 (en büyük pozitif 32-bit sayıdan 1 fazla) veya daha büyükse geçerlidir.
        if result >= (1 << 31):
            result -= (1 << 32)
            
        return result
