class Solution {
public:
    int singleNumber(vector<int>& nums) {
int result = 0;
        
        // Her bit pozisyonu için döngü (bir int 32 bit olduğu için)
        for (int i = 0; i < 32; ++i) {
            int sum_bits = 0;
            // Dizideki her sayıyı kontrol et
            for (int num : nums) {
                // Sayının i'inci bitini al
                if ((num >> i) & 1) {
                    sum_bits++;
                }
            }
            // Eğer i'inci bitin toplamı 3'e bölündüğünde 1 kalıyorsa,
            // bu, tek sayının i'inci bitinin 1 olduğu anlamına gelir.
            if (sum_bits % 3 == 1) {
                result |= (1 << i); // Sonuca bu biti ekle
            }
        }
        
        return result;
    }
};
