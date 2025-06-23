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

        // base case (amount == 0)
        for (int i = 0; i < coins.length; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i < coins.length; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                int take = Integer.MAX_VALUE;
                int notTake = Integer.MAX_VALUE;

                // take 
                if (coins[i] <= amt) {
                    int result = dp[i][amt - coins[i]];
                    if (result != Integer.MAX_VALUE) take = result + 1;
                }


                // not take 
                if (i != 0) {
                    notTake = dp[i - 1][amt];
                }

                dp[i][amt] = Integer.min(take,notTake);
            }
        }
        
        return dp[coins.length - 1][amount] == Integer.MAX_VALUE ? -1: dp[coins.length - 1][amount];
    }

    int minCoins (int[] coins, int idx, int amount) {
        // base case 
        if (idx < 0) return Integer.MAX_VALUE;
        if (amount == 0) return 0;

        if (dp[idx][amount] != -1) return dp[idx][amount];
        

        int take = Integer.MAX_VALUE;
        int notTake = Integer.MAX_VALUE;
        
        // take 
        if (coins[idx] <= amount) {
            int result = minCoins(coins, idx, amount - coins[idx]);
            if (result != Integer.MAX_VALUE) take = result + 1;
        }

        // not take 
        notTake = minCoins(coins, idx - 1, amount);

        dp[idx][amount] = Math.min(take, notTake);

        return dp[idx][amount];
    }
    
}