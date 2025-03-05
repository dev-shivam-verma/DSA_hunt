class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        std::vector<int> prev(m + 1, 0), cur(m + 1, 0);
    // Tabulation with space optimization
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
            } else {
                cur[j] = std::max(prev[j], cur[j - 1]);
            }
        }
        // Move current row to previous row for next iteration
        std::swap(prev, cur);
    }

        return prev[m];
    }


    int recursion(int i, int j, string &text1, string &text2){

        if (i < 0 || j < 0) return 0;
        if (i == 0 && j == 0) return text1[i] == text2[j];


        int longestSubseq = 0;
        if (text1[i] == text2[j]){
            longestSubseq = 1 + recursion(i - 1, j - 1, text1, text2);
        } else {
            longestSubseq = recursion(i, j - 1, text1, text2);
            longestSubseq = max(longestSubseq, recursion(i - 1, j, text1, text2));
        }

        return longestSubseq;
    }
};