class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        
        # dp listesi, i. basamağa kaç farklı şekilde ulaşılabileceğini tutar.
        # dp[0] kullanılmayacak, dp[1] ilk basamak, dp[2] ikinci basamak.
        # Boyut n+1, böylece dp[n] erişilebilir olur.
        dp = [0] * (n + 1)
        
        # Başlangıç durumları
        dp[1] = 1 # 1. basamağa 1 farklı şekilde ulaşılabilir (1 adım)
        dp[2] = 2 # 2. basamağa 2 farklı şekilde ulaşılabilir (1+1 adım, veya 2 adım)
        
        # Dinamik programlama yaklaşımı
        # i. basamağa ulaşmak için (i-1). basamaktan 1 adım atılabilir
        # veya (i-2). basamaktan 2 adım atılabilir.
        # Yani dp[i] = dp[i-1] + dp[i-2]
        for i in range(3, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
            
        return dp[n]
