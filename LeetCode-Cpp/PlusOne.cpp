class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // En sağdaki basamaktan başlayarak sola doğru ilerle
        for (int i = n - 1; i >= 0; --i) {
            // Eğer mevcut basamak 9'dan küçükse, sadece artır ve sonucu döndür.
            // Çünkü bu durumda bir taşıma (carry) olmaz.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // Eğer mevcut basamak 9 ise, onu 0 yap ve taşıma bir sonraki basamağa geçer.
            digits[i] = 0;
        }

        // Eğer döngü biterse (yani tüm basamaklar 9 ise, örneğin [9,9,9]),
        // bu, sayının başına yeni bir '1' eklenmesi gerektiği anlamına gelir.
        // Örneğin, [9,9,9] -> [0,0,0] olduktan sonra, başına 1 ekleyerek [1,0,0,0] olur.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
