class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<vector<int>> dp(m, vector<int> (n, -1));

        // base case
        for (int j = 0; j < n; j++){
            int i = m-1;
            dp[i][j] = triangle[i][j];
        }


        // tabulation
        for (int i = m-2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                int curr = triangle[i][j];
                int d = dp[i + 1][j] + curr;
                int dg = dp[i + 1][j + 1] + curr;

                dp[i][j] = min(d, dg);
            }
        }

        return dp[0][0];
    }


   



};