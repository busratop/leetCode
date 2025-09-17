class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        total_sum = sum(nums)
    
        # Kadane: max subarray sum (normal)
        max_sum = cur_max = nums[0]
        for num in nums[1:]:
            cur_max = max(num, cur_max + num)
            max_sum = max(max_sum, cur_max)
        
        # Kadane: min subarray sum (for circular case)
        min_sum = cur_min = nums[0]
        for num in nums[1:]:
            cur_min = min(num, cur_min + num)
            min_sum = min(min_sum, cur_min)
        
        # Eğer tüm elemanlar negatifse, circular toplam işe yaramaz
        if max_sum < 0:
            return max_sum
        
        return max(max_sum, total_sum - min_sum)
