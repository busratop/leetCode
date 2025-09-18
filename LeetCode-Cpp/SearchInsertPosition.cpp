class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
              int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // overflow riskini önlemek için böyle yazılır
            if (nums[mid] == target) {
                return mid;  // bulundu
            } else if (nums[mid] < target) {
                left = mid + 1;  // sağ tarafa bak
            } else {
                right = mid - 1; // sol tarafa bak
            }
        }
        
        // bulunamazsa, left zaten target'ın eklenmesi gereken pozisyonu gösterir
        return left;
    }
};
