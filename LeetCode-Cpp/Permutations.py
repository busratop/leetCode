class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;       // Tüm permütasyonları tutacak
        vector<int> current;              // Geçici olarak oluşturulan permütasyon
        vector<bool> used(nums.size(), false); // Hangi elemanların kullanıldığını takip eder

        backtrack(nums, used, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current); // Tam bir permütasyon oluştu
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue; // Bu eleman zaten kullanıldıysa atla

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result); // Recursive çağrı

            // Geri izleme: son eklenen elemanı çıkar ve işaretlemeyi kaldır
            current.pop_back();
            used[i] = false;
        }
    }

};
