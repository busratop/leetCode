class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        # Dizideki tüm sayıları XOR ile birleştir.
        # Aynı sayılar birbirini götürecektir (a ^ a = 0).
        # Sonuç olarak sadece tek olan sayı kalacaktır.
        for num in nums:
            result ^= num
        return result
