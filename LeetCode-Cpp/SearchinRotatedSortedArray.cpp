class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // hedef bulundu
            }

            // Sol taraf sıralı mı?
            if (nums[left] <= nums[mid]) {
                // Target sol tarafta mı?
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // sola kay
                } else {
                    left = mid + 1; // sağa kay
                }
            }
            // Yoksa sağ taraf sıralı
            else {
                // Target sağ tarafta mı?
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // sağa kay
                } else {
                    right = mid - 1; // sola kay
                }
            }
        }
        return -1; // bulunamazsa
    }
};
