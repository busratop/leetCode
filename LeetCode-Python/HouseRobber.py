class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        # Temel durumlar (Base cases)
        # Eğer hiç ev yoksa, çalınacak para 0'dır.
        if n == 0:
            return 0
        # Eğer tek bir ev varsa, o evin tüm parasını çalabiliriz.
        if n == 1:
            return nums[0]

        # Dinamik programlama için iki değişken kullanarak alanı optimize ediyoruz.
        # dp_i_minus_2: İki ev önceki duruma kadar çalınabilecek maksimum para (f(k-2))
        # dp_i_minus_1: Bir ev önceki duruma kadar çalınabilecek maksimum para (f(k-1))
        dp_i_minus_2 = 0
        dp_i_minus_1 = 0

        # nums dizisindeki her evi iteratif olarak işliyoruz
        for num in nums: # num, mevcut evin değeridir
            # Mevcut ev (num) için maksimum çalınabilecek para hesaplanır.
            # İki seçeneğimiz var:
            # 1. Mevcut evi soy: num + dp_i_minus_2 (Çünkü bu durumda önceki evi soyamayız, bu yüzden iki ev önceki duruma kadar olan maksimumu ekleriz)
            # 2. Mevcut evi soyma: dp_i_minus_1 (Bu durumda önceki eve kadar olan maksimum parayı alırız)
            current_dp_i = max(dp_i_minus_1, num + dp_i_minus_2)

            # Değişkenleri bir sonraki adım için güncelliyoruz:
            # Bir önceki (dp_i_minus_1) değerini, iki önceki (dp_i_minus_2) değerine atarız.
            dp_i_minus_2 = dp_i_minus_1
            # Mevcut (current_dp_i) değerini, bir önceki (dp_i_minus_1) değerine atarız.
            dp_i_minus_1 = current_dp_i
        
        # Döngü tamamlandığında, dp_i_minus_1 değişkeni son eve kadar çalınabilecek maksimum parayı tutar.
        return dp_i_minus_1
