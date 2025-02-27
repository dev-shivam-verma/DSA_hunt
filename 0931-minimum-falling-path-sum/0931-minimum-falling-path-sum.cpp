class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minPath = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(matrix.size(), vector(matrix.size(), -1));

        // base case
        for (int i = 0; i < n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for (int idx = n-2; idx >= 0; idx--){
            for (int pos = 0; pos < n; pos++){
                int mini = INT_MAX;
                int current = matrix[idx][pos];

                for (int j = -1; j <= 1; j++){
                    int newPos = pos + j;

                    if (newPos >= 0 && newPos < n){

                        mini = min(mini, current + dp[idx + 1][newPos]);
                    }
                }

                dp[idx][pos] = mini;
            }
        }


        for (int i = 0; i < n; i++){
            minPath = min(minPath, dp[0][i]);
        }

        return minPath;
    }

    
};