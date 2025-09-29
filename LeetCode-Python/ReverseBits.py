class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0
        
        # 32 bitin her birini tek tek işleriz
        for i in range(32):
            # Sonucu bir bit sola kaydırarak yeni bit için yer açarız
            result <<= 1
            
            # n'in en sağdaki bitini (LSB - Least Significant Bit) alırız
            # ve bunu sonucun en sağdaki yerine ekleriz
            # (n & 1) işlemi n'in en sağdaki bitini verir.
            # Örneğin, eğer n'in en sağdaki biti 1 ise, (n & 1) 1 olur.
            # Eğer 0 ise, (n & 1) 0 olur.
            result |= (n & 1)
            
            # n'i bir bit sağa kaydırarak bir sonraki bit için hazırlanırız
            # Python'da sağa kaydırma operatörü (>>) negatif sayılar için aritmetik kaydırma yapar,
            # ancak n pozitif bir tamsayı olduğu sürece bu bir sorun teşkil etmez.
            n >>= 1
            
        return result
