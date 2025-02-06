class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return recursion(m - 1, n - 1, obstacleGrid, dp);
    }

    int recursion(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){

        if (grid[m][n] == 1) return 0;
        if (m == 0 && n == 0) return 1;

        int ways = 0;
        if (m > 0 && grid[m - 1][n] != 1){
            ways += dp[m - 1][n] != -1? dp[m - 1][n]: recursion(m - 1, n, grid, dp);
        }

        if (n > 0 && grid[m][n - 1] != 1){
            ways += dp[m][n - 1] != -1? dp[m][n - 1]: recursion(m, n - 1, grid, dp);
        }

        dp[m][n] = ways;
        return ways;
    }
};