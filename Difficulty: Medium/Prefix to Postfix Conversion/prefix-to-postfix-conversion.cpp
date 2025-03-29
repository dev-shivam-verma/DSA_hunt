//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        string copy = pre_exp;
        reverse(copy.begin(), copy.end());
        
        
        stack<string> stk;
        for (char i: copy){
            if (isalnum(i)){
                string operand{i};
                stk.push(operand);
            } else {
                string sub_op = "";
                
                for (int i = 0; i < 2; i++){
                    if (!stk.empty()){
                        sub_op += stk.top();
                        stk.pop();
                    }
                }
                
                sub_op += i;
                stk.push(sub_op);
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends