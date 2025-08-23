class Solution {
    int dp[][];

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int dp[][] = new int[n + 1][amount + 1];

        for (int i = 0; i <= amount; i++) {
            dp[0][i] = Integer.MAX_VALUE;
        }    
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int amt = 0; amt <= amount; amt++) {
                int take = Integer.MAX_VALUE;

                if (coins[i - 1] <= amt) {
                    int result = dp[i][amt - coins[i - 1]] ;
                    if (result != Integer.MAX_VALUE) {
                        take = result + 1;
                    }
                } 
                
                int notTake = dp[i - 1][amt];
                

                dp[i][amt] = Math.min(take, notTake);
            } 
        }

        return dp[n][amount] == Integer.MAX_VALUE? -1: dp[n][amount];
    }


}