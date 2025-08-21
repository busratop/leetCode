class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         // adjacency list ve indegree (giriş derecesi) dizisi
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // bi -> ai (bi önce, sonra ai) kenarlarını kur
        for (const auto& p : prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }

        // giriş derecesi 0 olanları kuyruğa koy (hiç önkoşulu olmayan dersler)
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        int taken = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            taken++; // bu dersi "aldık"

            // u'dan çıkan kenarlar: komşuların indegree'ini azalt
            for (int v : adj[u]) {
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        // tüm dersler alınabildiyse döngü yoktur
        return taken == numCourses;
    }
};
