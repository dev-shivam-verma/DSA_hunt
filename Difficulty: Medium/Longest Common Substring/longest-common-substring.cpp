//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        
        int x = s1.size(), y = s2.size();
        
        vector<int> prev(y + 1, 0);
        vector<int> cur(y + 1, 0);
        
        int maxLen = 0;
        
        for (int i = 1; i <= x; i++){
            for (int j = 1; j <= y; j++){
                if (s1[i-1] == s2[j-1]) cur[j] = prev[j-1] + 1;
                else cur[j] = 0;
                
                if (cur[j] > maxLen) maxLen = cur[j];
            }
            
            prev = cur;
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends