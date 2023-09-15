class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0)res = nums[i];
            count += (res == nums[i]) ? 1 : -1;
        }
        return res;
    }
};