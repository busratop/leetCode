class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shift = 0
        # left ve right eşit olana kadar her iki sayıyı da sağa kaydır
        # Böylece ortak öneki buluruz.
        while left != right:
            left >>= 1  # left = left // 2
            right >>= 1 # right = right // 2
            shift += 1
        
        # Ortak öneki bulduktan sonra, onu başlangıçtaki pozisyonuna geri kaydır.
        # Bu, farklılaşan bitlerin 0 olmasını sağlar.
        return left << shift # left = left * (2^shift)
