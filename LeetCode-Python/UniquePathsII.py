class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1:
            return 0
        obstacleGrid[0][0] = 1
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                if obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] = 0
                else:
                    top = obstacleGrid[i-1][j] if i > 0 else 0
                    left = obstacleGrid[i][j-1] if j > 0 else 0
                    obstacleGrid[i][j] = top + left
        
        return obstacleGrid[-1][-1]
