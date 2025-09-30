class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n != 0:
            n &= (n - 1) # Brian Kernighan algoritması: En düşük anlamlı 1 bitini temizler
            count += 1
        return count
