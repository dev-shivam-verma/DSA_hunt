class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int x = str1.size(), y = str2.size();
        
        vector<vector<int>> dp(x + 1, vector<int> (y + 1, 0));


        for (int i = 1; i <= x; i++){
            for (int j = 1; j <= y; j++){
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = x, j = y; 
        string ans = "";

        while (i > 0 && j > 0){
            if (str1[i - 1] == str2[j - 1]){
                ans += str1[i - 1];
                i--; j--;
            } else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    ans += str2[j - 1]; 
                    j--;
                } else {
                    ans += str1[i - 1];
                    i--;
                }
            }
        }

        while (j > 0){
            ans += str2[j - 1];
            j--;
        }

        while (i > 0){
            ans += str1[i - 1];
            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    
};