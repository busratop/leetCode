class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Pruning için sıralama (opsiyonel ama faydalı)
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, target, candidates, path, ans);
        return ans;
    }

private:
    void dfs(int start, int remain,
             const vector<int>& cand,
             vector<int>& path,
             vector<vector<int>>& ans) {
        if (remain == 0) {            // hedefe ulaştık
            ans.push_back(path);
            return;
        }
        for (int i = start; i < (int)cand.size(); ++i) {
            if (cand[i] > remain) break; // sıralı olduğundan sonrası da büyük olacaktır (pruning)
            // cand[i]’yi seç
            path.push_back(cand[i]);
            // Aynı elemanı tekrar kullanabildiğimiz için i'yi değişmeden gönderiyoruz
            dfs(i, remain - cand[i], cand, path, ans);
            // Geri al (backtrack)
            path.pop_back();
        }
    }
};
