class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1.0
        
        # Eğer n negatifse, x'i 1/x yaparız ve n'i pozitif hale getiririz.
        # Örneğin, x^-n = (1/x)^n
        if n < 0:
            x = 1 / x
            n = -n
        
        # İkili üs alma (binary exponentiation) algoritması
        # n, döngü içinde sıfıra yaklaşana kadar devam eder.
        while n > 0:
            # Eğer n tek ise, şu anki x değerini sonuca çarp.
            # n & 1, n % 2 == 1 ile aynıdır ve bitwise operatör olduğu için biraz daha hızlı olabilir.
            if n & 1: 
                ans *= x
            
            # x'i kare al ve n'i yarıya böl (tam sayı bölme).
            x *= x
            n >>= 1 # n >>= 1, n = n // 2 ile aynıdır.
            
        return ans
