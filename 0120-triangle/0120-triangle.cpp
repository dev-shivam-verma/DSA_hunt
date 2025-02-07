class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return recursion(0, 0, triangle, dp);
    }


    int recursion(int idx, int prev, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if (idx == triangle.size()) return 0;

        int curr, next = INT_MAX; 
        curr = triangle[idx][prev];
        curr += dp[idx + 1][prev] != -1? dp[idx + 1][prev] : recursion(idx + 1, prev, triangle, dp);

        if (prev + 1 < triangle[idx].size()){
            next = triangle[idx][prev + 1];
            next += dp[idx + 1][prev + 1] != -1? dp[idx + 1][prev + 1]: recursion(idx + 1, prev + 1, triangle, dp);
        }

        dp[idx][prev] = min(curr, next);
        return dp[idx][prev];
    }
};