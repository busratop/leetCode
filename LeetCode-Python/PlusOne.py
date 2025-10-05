class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)

        # En sağdaki basamaktan başlayarak sola doğru ilerle
        for i in range(n - 1, -1, -1):
            # Eğer mevcut basamak 9'dan küçükse, sadece artır ve sonucu döndür.
            # Çünkü bu durumda bir taşıma (carry) olmaz.
            if digits[i] < 9:
                digits[i] += 1
                return digits
            # Eğer mevcut basamak 9 ise, onu 0 yap ve taşıma bir sonraki basamağa geçer.
            digits[i] = 0

        # Eğer döngü biterse (yani tüm basamaklar 9 ise, örneğin [9,9,9]),
        # bu, sayının başına yeni bir '1' eklenmesi gerektiği anlamına gelir.
        # Örneğin, [9,9,9] -> [0,0,0] olduktan sonra, başına 1 ekleyerek [1,0,0,0] olur.
        return [1] + digits
