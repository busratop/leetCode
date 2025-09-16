class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            // Yeni alt dizi başlatmak mı daha iyi, yoksa mevcut alt diziye devam etmek mi?
            currentSum = max(nums[i], currentSum + nums[i]);
            // Şu ana kadarki en büyük toplamı güncelle
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;

    }
};
