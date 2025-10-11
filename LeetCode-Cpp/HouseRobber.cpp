class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Temel durumlar (Base cases)
        // Eğer hiç ev yoksa, çalınacak para 0'dır.
        if (n == 0) {
            return 0;
        }
        // Eğer tek bir ev varsa, o evin tüm parasını çalabiliriz.
        if (n == 1) {
            return nums[0];
        }

        // Dinamik programlama için iki değişken kullanarak alanı optimize ediyoruz.
        // dp_i_minus_2: İki ev önceki duruma kadar çalınabilecek maksimum para (f(k-2))
        // dp_i_minus_1: Bir ev önceki duruma kadar çalınabilecek maksimum para (f(k-1))
        int dp_i_minus_2 = 0;
        int dp_i_minus_1 = 0;

        // nums dizisindeki her evi iteratif olarak işliyoruz
        for (int i = 0; i < n; ++i) {
            // Mevcut ev (i). için maksimum çalınabilecek para hesaplanır.
            // İki seçeneğimiz var:
            // 1. Mevcut evi soy: nums[i] + dp_i_minus_2 (Çünkü bu durumda (i-1). evi soyamayız, bu yüzden (i-2). eve kadar olan maksimumu ekleriz)
            // 2. Mevcut evi soyma: dp_i_minus_1 (Bu durumda (i-1). eve kadar olan maksimum parayı alırız)
            int current_dp_i = max(dp_i_minus_1, nums[i] + dp_i_minus_2);

            // Değişkenleri bir sonraki adım için güncelliyoruz:
            // Bir önceki (i-1) değerini, iki önceki (i-2) değerine atarız.
            dp_i_minus_2 = dp_i_minus_1;
            // Mevcut (i) değerini, bir önceki (i-1) değerine atarız.
            dp_i_minus_1 = current_dp_i;
        }

        // Döngü tamamlandığında, dp_i_minus_1 değişkeni son eve kadar çalınabilecek maksimum parayı tutar.
        return dp_i_minus_1;
    }
};
