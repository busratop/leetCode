class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int jumps = 0; // Atlama sayısı, sonuca ulaşmak için gereken minimum atlama sayısını temsil eder.
        int current_max_reach = 0; // Şu anki adımda ulaşabileceğiniz maksimum endeks.
        int max_reach = 0; // Daha fazla atlama yaparak ulaşabileceğiniz maksimum endeks.

        for (int i = 0; i < n - 1; i++) {
            max_reach = std::max(max_reach, i + nums[i]); // Şu anki adımda ulaşabileceğiniz maksimum endeksi günceller.

            if (i == current_max_reach) {
                jumps++;
                current_max_reach = max_reach; // Şu anki adımda ulaşabileceğiniz maksimum endeksi günceller ve bir atlama ekler.
            }
        }

        return jumps; 
        }
};