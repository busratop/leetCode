class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: 
            return 0
        def dfs(grid, i, j): 
            if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == '0': 
                return 
            grid[i][j] = '0' # Ziyaret edilen '1'leri '0' yaparak işaretliyoruz 
            dfs(grid, i + 1, j) # alt 
            dfs(grid, i - 1, j) # üst 
            dfs(grid, i, j + 1) # sağ 
            dfs(grid, i, j - 1) # sol 
        num_islands = 0 
        for i in range(len(grid)): 
            for j in range(len(grid[0])): 
                if grid[i][j] == '1': # Yeni bir ada bulduk 
                    num_islands += 1 
                    dfs(grid, i, j) # DFS ile tüm adayı ziyaret ediyoruz 
        return num_islands
