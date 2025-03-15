//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        
        int maxi = 0;
        int lastIndex = 0;
        
        for (int i = 0; i < n; i++){
            hash[i] = i;
            
            for (int j = 0; j < i; j++){
                if (arr[j] < arr[i] && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            
            if (dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
            
        }
        
        vector<int> ans;
        ans.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends