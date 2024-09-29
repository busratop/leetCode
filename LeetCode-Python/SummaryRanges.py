class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        break_point = 0
        k = 0
        res = []

        if len(nums) == 1:
            res.append(f"{nums[0]}")

        for i in range(1, len(nums)):
            
            if nums[i] - nums[k] > 1:
                if nums[break_point] == nums[k]:
                    res.append(f"{nums[i - 1]}")
                else:
                    res.append(f"{nums[break_point]}->{nums[k]}")
                break_point = i


            if i == len(nums) - 1:
                if nums[break_point] == nums[i]:
                    res.append(f"{nums[i]}")
                else:
                    res.append(f"{nums[break_point]}->{nums[i]}")

            k += 1

        return res
