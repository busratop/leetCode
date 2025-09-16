class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = current_sum = nums[0]

        for num in nums[1:]:
            # Yeni alt dizi başlatmak mı, yoksa mevcut alt diziye devam etmek mi?
            current_sum = max(num, current_sum + num)
            # Şu ana kadarki en büyük toplamı güncelle
            max_sum = max(max_sum, current_sum)

        return max_sum
