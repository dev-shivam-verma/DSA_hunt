class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size(), vector<int> (amount + 1, -2));

        return recursion(coins.size() - 1, amount, coins, dp);
    }

    int recursion(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){

        if (amount == 0) return 0;
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount/coins[0];
            return -1;
        }

        if (dp[idx][amount] != -2) return dp[idx][amount];

        int notTaken = recursion(idx - 1, amount, coins, dp);
        int taken = -1;
        if (amount >= coins[idx]){
            int maxCoins = amount/coins[idx];
            int minCoins = INT_MAX;

            for (int i = 1; i <= maxCoins; i++){
                int futureCoins = recursion(idx - 1, amount - i * coins[idx], coins, dp);
                if (futureCoins != -1){
                    minCoins = min(minCoins, i + futureCoins);
                }
            }
            taken = minCoins == INT_MAX? -1: minCoins; 
        }

        int ans;
        if (taken == -1 && notTaken == -1){
            ans = -1;
        } else if (taken == -1 ) ans = notTaken;
        else if (notTaken == -1) ans = taken;
        else ans = min(taken, notTaken);

        
        return dp[idx][amount] = ans;
    }
};