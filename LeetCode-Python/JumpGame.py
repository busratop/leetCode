class Solution:
    def canJump(self, nums: List[int]) -> bool:
        l = len(nums)

        if l==1:
            return True
        s = nums[0]

        for i in range(l-1):
            if nums[i] > s:
                s = nums[i]
            s = s - 1
            if s < 0 :
                return False
        return True