class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         // Adjacency list ve in-degree dizisi
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // Kenarlar: b -> a (a için önce b alınmalı)
        for (const auto& p : prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }

        // in-degree'i 0 olan dersleri kuyruğa at
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);

        vector<int> order;
        order.reserve(numCourses);

        // BFS
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        // Tüm dersler eklendiyse geçerli sıra; yoksa döngü var demektir
        if ((int)order.size() == numCourses) return order;
        return {};
    }
};
