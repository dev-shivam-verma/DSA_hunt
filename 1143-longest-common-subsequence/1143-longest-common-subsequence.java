class Solution {

    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int[] prev = new int[m + 1];

        for (int i = 1; i <= n; i++) {
            int[] cur = new int[m + 1];
            for (int j = 1; j <= m; j++) {
                int result = 0;

                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    result = prev[j - 1] + 1;
                } else {
                    result = prev[j];
                    result = Math.max(result, cur[j - 1]);
                }

                cur[j] = result;
            }
            prev = cur;
        }

        return prev[m];
    }

    int f(int i, int j, String a, String b) {
        if (i < 1 || j < 1) return 0;

        int result = 0;
        if (a.charAt(i - 1) == b.charAt(j - 1)) {
            result = f(i - 1, j - 1, a, b) + 1;
        } else {
            result = f(i - 1, j, a , b);
            result = Math.max(result, f(i, j - 1, a, b));
        }

        return result; 
    }

}