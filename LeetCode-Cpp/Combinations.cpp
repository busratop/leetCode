class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        // Başlatıcı fonksiyon
        backtrack(1, n, k, current, result);
        return result;
    }
    private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        // Eğer k elemanlı bir kombinasyon oluşturulduysa, sonucu ekle
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Adayları sırayla dene
        for (int i = start; i <= n; ++i) {
            current.push_back(i);                  // Elemanı ekle
            backtrack(i + 1, n, k, current, result); // Bir sonraki eleman için recursive çağrı
            current.pop_back();                    // Geri izleme (backtrack)
        }
    }
};
