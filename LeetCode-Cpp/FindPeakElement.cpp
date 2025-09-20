class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Eğer orta eleman, sağındaki elemandan küçükse
            // o zaman peak sağ tarafta olmalı
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // Aksi durumda peak solda veya mid’de olabilir
            else {
                right = mid;
            }
        }
        
        // left == right olduğunda peak bulundu
        return left;
    }
};
