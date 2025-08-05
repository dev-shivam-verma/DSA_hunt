class Solution {
    int[][] dp;

    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ans = 0;

                if (text1.charAt(i) == text2.charAt(j)) {
                    ans++;
                    if (i > 0 && j > 0) ans += dp[i - 1][j - 1]; 
                } else {
                    if (i > 0) {
                        ans = dp[i - 1][j];
                    }

                    if (j > 0) {
                        ans = Math.max(ans, dp[i][j - 1]);
                    }
                }

                dp[i][j] = ans;
            }
        }
        
        return dp[n - 1][m - 1];
    }


}