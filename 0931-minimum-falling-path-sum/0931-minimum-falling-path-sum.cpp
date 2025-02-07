class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix.size(), -1));


        // base case
        for (int i = 0; i < n; i++){
            dp[n - 1][i] = matrix[n - 1][i]; 
        }

        // tabulation
        for (int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int curr = matrix[i][j];

                int minPath = dp[i + 1][j];
                if (j > 0) minPath = min(minPath, dp[i + 1][j - 1]);
                if (j + 1 < n) minPath = min(minPath, dp[i + 1][j + 1]);

                dp[i][j] = minPath + curr;
            }
        } 


        for (int i = 0; i < n; i++){
            ans= min(dp[0][i], ans);
        }

        return ans;
    }

};