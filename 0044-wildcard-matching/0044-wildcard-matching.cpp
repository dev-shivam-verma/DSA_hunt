class Solution {
public:
    bool isMatch(string s, string p) {
        int x = s.size() , y = p.size();

        vector<vector<bool>> dp(x + 1, vector<bool> (y + 1, false));

        // base case
        dp[0][0] = true;
        for (int j = 1; j <= y; j++){
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
        }

        for (int i = 1; i <= x; i++){
            for (int j = 1; j <= y; j++){
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[x][y];
    }


    bool f(int i, int j, string s, string p){
        if (i < 0 && j < 0) return true;
        if (i < 0 || j < 0) return false;

        if (s[i] == p[j] || p[j] == '?') return f(i - 1, j - 1, s, p);
        if (p[j] == '*') {
            return i >= j ? f(j - 1, j - 1, s, p) : f(i, j - 1, s, p);
        }
        return f(i - 1, j, s, p);
    }


};