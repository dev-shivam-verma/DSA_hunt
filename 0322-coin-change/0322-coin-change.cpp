class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size(), vector<int> (amount + 1, -1));

        int result = recursion(coins.size() - 1, amount, coins, dp);
        if (result >= 1e9) return -1;
        return result;
    }

    int recursion(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){

        if (amount == 0) return 0;
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notTaken = recursion(idx - 1, amount, coins, dp);
        int taken = 1e9;
        if (amount >= coins[idx]){
            taken = 1 + recursion(idx, amount - coins[idx], coins, dp);
        }


        
        return dp[idx][amount] = min(taken, notTaken);
    }
};