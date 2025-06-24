class Solution {
    int[] denominations;
    int[][] dp;


    public List<Integer> findCoins(int[] numWays) {
        int n = numWays.length;
        denominations = new int[n + 1];
        dp = new int[n + 1][n + 1];

        // base case initialization
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
            dp[i][0] = 0;
        }         


        for (int amt = 1; amt <= n; amt++) {
            for (int denm = 1; denm <= n; denm++) {
                int take = 0;
                int notTake = 0;

                if (denominations[denm] != 0 && denm <= amt) {
                    take = dp[amt - denm][denm];
                }
                notTake = dp[amt][denm - 1];

                dp[amt][denm] = take + notTake;

                if (amt == denm ) {

                    if (dp[amt][denm] < numWays[amt - 1]) {
                        dp[amt][denm] += 1;
                        denominations[amt] = 1;
                    }
                    

                    if (dp[amt][denm] != numWays[amt - 1]) return new ArrayList<Integer>();
                }
            }
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            if (denominations[i] != 0) ans.add(i);
        }

        return ans;
    }
}