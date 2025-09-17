class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], curMax = nums[0];
        int minSum = nums[0], curMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            // Kadane's algorithm for max subarray sum
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            // Kadane's algorithm for min subarray sum
            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);

            totalSum += num;
        }

        totalSum += nums[0]; // nums[0] was skipped in the loop

        // Eğer tüm elemanlar negatifse, circular toplam işe yaramaz
        if (maxSum < 0) return maxSum;

        // max of normal max subarray or circular subarray
        return max(maxSum, totalSum - minSum);

    }
};
