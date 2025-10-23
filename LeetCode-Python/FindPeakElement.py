class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            
            # Eğer orta eleman sağındaki elemandan küçükse
            # peak sağ tarafta olmalı
            if nums[mid] < nums[mid + 1]:
                left = mid + 1
            else:
                # peak solda ya da mid’de olabilir
                right = mid
        
        # left == right olduğunda peak bulundu
        return left
