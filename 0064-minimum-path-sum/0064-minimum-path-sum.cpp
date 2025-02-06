class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return recursion(m - 1, n - 1, grid, dp);
    }

    int recursion(int m, int n, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if (m == 0 && n == 0) return grid[0][0];

        int up = INT_MAX, left = INT_MAX;
        int curr = grid[m][n];
        if (m > 0) {
                up = curr;
                up += dp[m-1][n] != -1? dp[m-1][n] : recursion(m - 1, n, grid, dp);
            }
        if (n > 0) {
                left = curr;
                left += dp[m][n-1] != -1? dp[m][n - 1] : recursion(m, n - 1, grid, dp);
            }


        dp[m][n] = min(up, left);
        return dp[m][n];
    }
};