class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int y = s.size();

        vector<int> prev(y, 0);
        vector<int> cur(y, 0);

        for (int i = y - 1; i >= 0; i--){
            for (int j = 0; j < y; j++){
                if (i == j) cur[j] = 1;
                else if (i > j) cur[j] = 0;
                else {
                    if (s[i] == s[j]){
                        cur[j] = 2 + prev[j - 1];
                    } else {
                        cur[j] = max(prev[j], cur[j - 1]);
                    }
                }
            }

            prev = cur;
        }

        return prev[y - 1];
    }

    int recursion(int i, int j, string s){
        if (i == j) return 1;
        if (j < i) return 0;

        int ans = 0;
        if (s[i] == s[j]) ans = 2 + recursion(i + 1, j - 1, s);
        else {
            ans = max(recursion(i + 1, j, s), recursion(i, j - 1, s));
        } 

        return ans;
    }
};