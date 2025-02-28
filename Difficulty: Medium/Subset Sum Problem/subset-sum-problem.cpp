//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return backtracking(arr, target, arr.size() - 1, dp);
    }
    
    bool backtracking(vector<int>& arr, int target, int idx, vector<vector<int>>& dp){
        
        if (target < 0) return false;
        if (target == 0) return true;
        if (idx == 0){
            return target == arr[0];
        }
        
        // if previously calculated
        if (dp[idx][target] != -1) return dp[idx][target];
        
        bool notTaken = backtracking(arr, target, idx - 1, dp);
        bool taken = backtracking(arr, target - arr[idx], idx - 1, dp);
        
        dp[idx][target] = notTaken||taken;
        return notTaken||taken;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends