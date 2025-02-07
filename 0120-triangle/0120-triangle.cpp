class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<int> dp(n, -1);

        // base case
        for (int j = 0; j < n; j++){
            dp[j] = triangle[m - 1][j];
        }


        // tabulation with memory optemization
        for (int i = m-2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                int curr = triangle[i][j];
                int d = dp[j] + curr;
                int dg = dp[j + 1] + curr;

                dp[j] = min(d, dg);
            }
        }

        return dp[0];
    }


   



};