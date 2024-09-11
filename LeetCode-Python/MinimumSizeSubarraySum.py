class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        minLength = float('inf')

        left = 0
        sum_val = 0

        for right in range(n):
            sum_val += nums[right]

            while sum_val >= target:
                minLength = min(minLength, right - left + 1)
                sum_val -= nums[left]
                left += 1

        return 0 if minLength == float('inf') else minLength
