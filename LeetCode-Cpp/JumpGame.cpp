class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            l = max(l, nums[i]);
            l--;
            if (l == -1) return false;
        }

        return true;
    }
};