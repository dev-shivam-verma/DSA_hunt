class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robThis(n - 1, nums, dp);
    }

    int robThis(int idx, vector<int>& nums, vector<int>& dp){
        if (idx == 0) return nums[0];

        // if i rob this house
        int rob1 = nums[idx];
        if (idx > 1) {
            rob1 += dp[idx - 2] != -1? dp[idx - 2] : robThis(idx - 2, nums, dp);
        }

        // if i do not rob this
        int rob2 = dp[idx - 1] != -1 ? dp[idx - 1]: robThis(idx-1, nums, dp);
      
        dp[idx] = max(rob1, rob2);
        return dp[idx];
    }
};