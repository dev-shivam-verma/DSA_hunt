class Solution {
    private int[][] dp;

    public int coinChange(int[] coins, int amount) {
        dp = new int[coins.length][amount + 1];

        // dp initialization 
        for (int i = 0; i < coins.length; i++ ){
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = -1;
            }
        }

        int ans = minCoins(coins, coins.length - 1, amount, 0);
        
        return ans == Integer.MAX_VALUE ? -1: ans;
    }

    int minCoins (int[] coins, int idx, int amount, int coinsUsed) {
        // base case 
        if (idx < 0) return Integer.MAX_VALUE;
        if (amount == 0) return coinsUsed;

        if (dp[idx][amount] != -1) return dp[idx][amount];
        

        int take = Integer.MAX_VALUE;
        int notTake = Integer.MAX_VALUE;
        
        // take 
        if (coins[idx] <= amount) {
            take = minCoins(coins, idx, amount - coins[idx], coinsUsed + 1);
        }

        // not take 
        notTake = minCoins(coins, idx - 1, amount, coinsUsed);

        dp[idx][amount] = Math.min(take, notTake);

        return dp[idx][amount];
    }
    
}