class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            auto [square, moves] = q.front();
            q.pop();

            if (square == n * n) return moves;

            for (int i = 1; i <= 6 && square + i <= n * n; ++i) {
                int next = square + i;
                auto [row, col] = getPosition(next, n);
                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }

private:
    pair<int, int> getPosition(int s, int n) {
        int quot = (s - 1) / n;
        int rem = (s - 1) % n;
        int row = n - 1 - quot;
        int col = (quot % 2 == 0) ? rem : n - 1 - rem;
        return {row, col};
}
};
