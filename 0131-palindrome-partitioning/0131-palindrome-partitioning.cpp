class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        helper(ans,s, partition);

        return ans;
    }

    bool isPalindrome(string s){
        int i = 0, j = s.length() - 1;

        while (i <= j){
            if (s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }


    void helper(vector<vector<string>>& ans, string s, vector<string>& partition){
        
        int n = s.length();

        // base case 
        if (n == 0){
            ans.push_back(partition);
            return;
        }

        
        for (int i = 1; i <= n ; i++){
            string curr = s.substr(0,i);

            if (isPalindrome(curr)){

                partition.push_back(curr);
                s = i == n? "" : s.substr(i, n - i);

                helper(ans, s, partition);

                // backtracking 
                partition.pop_back();
                s = curr + s;
            }
        }    
    }
};