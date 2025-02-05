//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        vector<int> prevChoices(4,-1);
        vector<vector<int>> dp(arr.size(), prevChoices);
        return maxPoints(arr.size() - 1, 3, arr, dp);
    }
    
    
    // choice can be 0,1 or 2
    int maxPoints(int idx, int prevChoice, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if (idx == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if (i != prevChoice){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            
            return maxi;
        }
        
        int maxi = 0;
        
        for (int i = 0; i < 3; i++){
            if (i != prevChoice){
                int score = arr[idx][i];
                
                if (dp[idx - 1][i] != -1) score += dp[idx - 1][i];
                else score += maxPoints(idx - 1, i, arr, dp);
                
                maxi = max(maxi, score);
            } 
        }
        
        dp[idx][prevChoice] = maxi;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends