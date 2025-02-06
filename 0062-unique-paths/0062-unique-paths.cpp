class Solution {


public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return memoization(m - 1, n - 1, dp);
    }


    int memoization(int m, int n, vector<vector<int>>& dp){
        // base case
        if (m == 0 && n == 0) return 1;

        int ways = 0;
        if (m >= 1){
            ways += dp[m - 1][n] != -1 ? dp[m - 1][n] : memoization(m - 1, n, dp);
        }        
        if (n >= 1) {
            ways += dp[m][n - 1] != -1 ? dp[m][n - 1] : memoization(m , n - 1, dp);
        }

        dp[m][n] = ways;
        return ways;
    }
};