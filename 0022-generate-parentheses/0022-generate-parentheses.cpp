class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        
        paranthesis_generator("",0,0,n, ans);
        return ans; 
    }


    void paranthesis_generator(string sequence, int l, int r, int n, vector<string> &ans){
        if (l == n && r == n) {
            ans.push_back(sequence);
        }

        // left
        if (l + 1 <= n) {
            paranthesis_generator(sequence + "(", l + 1, r, n, ans);
        }

        // right
        if (r + 1 <= n && r + 1 <= l) {
            paranthesis_generator(sequence + ")", l, r + 1, n, ans);
        }
    }
};