class Solution {
    
    public int minXor(int[] nums, int k) {
        int n = nums.length;
        int[][]dp = new int[n][k];
        int[] pre = new int[n];

        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] ^ nums[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (j > i) {
                    dp[i][j] = Integer.MAX_VALUE;
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = pre[i];
                    continue;
                }

                int minMaxXor = Integer.MAX_VALUE;
                for (int t = i - 1; t >= 0; t--) {
                    int max = Math.max(dp[t][j-1], pre[i] ^ pre[t]);
                    minMaxXor = Math.min(max, minMaxXor);
                }

                dp[i][j] = minMaxXor;
            }
        }

        return dp[n-1][k-1];
    }

    
}