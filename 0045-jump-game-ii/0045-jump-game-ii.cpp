class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for (int i = n - 2; i >= 0; i--){
            int mini = 1e9;

            for (int j = 1; j <= nums[i]; j++){
                if (i + j < n) mini = min(mini, 1 + dp[i + j]);
            }
            dp[i] = mini;
        }
        return dp[0];
    }

    int f(int idx, vector<int>& nums){
        // base case
        if (idx >= nums.size() - 1) return 0;

        int mini = 1e9;

        for (int i = 1; i <= nums[idx]; i++){
            mini = min(mini, f(idx + i, nums) + 1);
        }


        return mini;
    }
};