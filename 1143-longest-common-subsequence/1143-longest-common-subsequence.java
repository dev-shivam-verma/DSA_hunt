class Solution {
    int[][] dp;

    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        
        return f(n - 1, m - 1, text1, text2);
    }


    public int f(int i, int j, String a, String b) {
        // base case
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];


        int ans;
        if (a.charAt(i) == b.charAt(j)) {
            ans = f(i - 1, j - 1, a, b) + 1;
        } else {
            int choiceA = f(i - 1, j, a, b);
            int choiceB = f(i, j - 1, a, b);

            ans = Math.max(choiceA, choiceB);
        }

        return dp[i][j] = ans;
    }
}