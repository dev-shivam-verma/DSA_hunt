class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] count = new int[n]; 
        Arrays.fill(dp, 1);
        Arrays.fill(count, 1);

        int lisLength = 1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    cnt = count[j];
                    dp[i] = dp[j] + 1;
                } else if (nums[i] > nums[j] && dp[j] + 1 == dp[i]) {
                    cnt += count[j];
                }
            }

            if (cnt > 1) count[i] = cnt;
            lisLength = Math.max(lisLength, dp[i]);
        }        

        int freq = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == lisLength) freq += count[i];
        }
        

        return freq;
    }
}