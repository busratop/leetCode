class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Grafik: node -> [(komsu, oran)]
        unordered_map<string, vector<pair<string, double>>> g;
        g.reserve(equations.size() * 2);

        // 1) Grafı kur
        for (size_t i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            double v = values[i];

            g[A].push_back({B, v});       // A / B = v
            g[B].push_back({A, 1.0 / v}); // B / A = 1/v
        }

        // 2) Her sorguyu çöz
        vector<double> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            const string& C = q[0];
            const string& D = q[1];

            // Değişkenlerden biri tanımsızsa
            if (!g.count(C) || !g.count(D)) {
                ans.push_back(-1.0);
                continue;
            }

            // Aynı değişkense ve grafikte varsa 1.0
            if (C == D) {
                ans.push_back(1.0);
                continue;
            }

            // DFS ile C'den D'ye yol ve çarpım ara
            unordered_set<string> vis;
            double result = -1.0;
            if (dfs(C, D, 1.0, vis, g, result)) {
                ans.push_back(result);
            } else {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }
    private:
    bool dfs(const string& cur, const string& target, double acc,
             unordered_set<string>& vis,
             unordered_map<string, vector<pair<string, double>>>& g,
             double& out) {
        if (cur == target) {
            out = acc;
            return true;
        }
        vis.insert(cur);

        for (auto& [nxt, w] : g[cur]) {
            if (vis.count(nxt)) continue;
            if (dfs(nxt, target, acc * w, vis, g, out)) {
                return true;
            }
        }
        return false;
    }

};
