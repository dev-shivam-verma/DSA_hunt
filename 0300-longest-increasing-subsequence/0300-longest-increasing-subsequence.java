class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int result = 0;
        int[][] dp = new int[n + 1][n + 2];


        for (int prev = n; prev >= 0; prev--) {
            for (int idx = n; idx >= 1; idx--) {
                int take = Integer.MIN_VALUE;

                if (prev == 0 || nums[prev - 1] < nums[idx - 1]) {
                    take = dp[idx][idx + 1] + 1;
                }

                int notTake = dp[prev][idx + 1];

                dp[prev][idx] = Math.max(take, notTake); 
            }
        }

        for (int i = 1; i <= n; i++) {
            result = Math.max(result, dp[0][i]);
        }

        return result;
    }


    


   
}