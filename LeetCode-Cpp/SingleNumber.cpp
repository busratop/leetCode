class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int result = 0;
        // Dizideki tüm sayıları XOR ile birleştir.
        // Aynı sayılar birbirini götürecektir (a ^ a = 0).
        // Sonuç olarak sadece tek olan sayı kalacaktır.
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};
