class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Sorting the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate triplets with the same first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int current_sum = nums[left] + nums[right];

                if (current_sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate triplets with the same second element
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate triplets with the same third element
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};
