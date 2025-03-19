class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(); 

        auto comparator = [](string a,string b) {
            return a.size() < b.size();
        };

        sort(words.begin(), words.end(), comparator);

        vector<int> dp(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (words[j].size() + 1 == words[i].size()){
                    int k = words[j].size(), l = words[i].size();
                    k--;l--;

                    while (k >= 0 && l >= 0){
                        if (words[j][k] == words[i][l]){
                            k--;l--;
                        } else {
                            l--;
                        }
                    }                    

                    if (k < 0){
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};