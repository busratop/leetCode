class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Eğer orta eleman sağdakinden büyükse,
            // minimum sağ tarafta demektir
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Aksi halde minimum soldadır (veya mid'dir)
                right = mid;
            }
        }

        // Döngü bittiğinde left == right ve minimum oradadır
        return nums[left];
    }
};

