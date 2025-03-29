//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> stk;
        string rev_pre = pre_exp;
        reverse(rev_pre.begin(), rev_pre.end());
        
        for (char i: rev_pre){
            if (isalnum(i)){
                string operand{i};
                stk.push(operand);
            } else {
                string sub_rs = "(";
                
                // getting the first operand
                if(!stk.empty()){
                    sub_rs += stk.top();
                    stk.pop();
                }
                
                // adding the operator 
                sub_rs += i;
                
                // getting the second operator
                if(!stk.empty()){
                    sub_rs += stk.top();
                    stk.pop();
                }
                
                sub_rs += ")";
                
                stk.push(sub_rs);
            }
        }
        
        string ans = "";
        
        if (!stk.empty()){
            ans = stk.top();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends