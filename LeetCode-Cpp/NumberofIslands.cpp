class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) { 
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') { 
            return; 
        } 
        grid[i][j] = '0'; // Ziyaret edilen '1'leri '0' yaparak işaretliyoruz 
        dfs(grid, i + 1, j); // alt 
        dfs(grid, i - 1, j); // üst 
        dfs(grid, i, j + 1); // sağ 
        dfs(grid, i, j - 1); // sol 
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0; 
        int num_islands = 0; 
        for (int i = 0; i < grid.size(); ++i) { 
            for (int j = 0; j < grid[0].size(); ++j) { 
                if (grid[i][j] == '1') { 
                    // Yeni bir ada bulduk 
                    ++num_islands; 
                    dfs(grid, i, j); // DFS ile tüm adayı ziyaret ediyoruz 
                } 
            } 
            
        } 
        return num_islands;
    }
};
