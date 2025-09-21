class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid  # hedef bulundu

            # Sol taraf sıralı mı?
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1  # sola kay
                else:
                    left = mid + 1   # sağa kay
            # Sağ taraf sıralı
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1   # sağa kay
                else:
                    right = mid - 1  # sola kay

        return -1  # bulunamadı
