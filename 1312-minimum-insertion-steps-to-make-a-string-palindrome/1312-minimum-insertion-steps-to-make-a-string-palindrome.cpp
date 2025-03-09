class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        vector<int> prev(n, 0);
        vector<int> cur(n, 0);

        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j < n; j++){
                if (j <= i) cur[j] = 0;
                else if (s[i] == s[j]) cur[j] = prev[j - 1];
                else {
                    cur[j] = min(1 + prev[j], 1 + cur[j - 1]);
                }
            }

            prev = cur;
        } 

        return prev[n - 1];
    }

    int recursion(int i, int j, string &s){
        if (j <= i) return 0;
        
        int ans = 0;
        if (s[i] == s[j]){
            ans = recursion(i + 1, j - 1, s);
        } else{
            int lAdd = 1 + recursion(i , j - 1, s);
            int rAdd = 1 + recursion(i + 1, j, s);
            ans = min(lAdd, rAdd);
        }

        return ans;
    }
};