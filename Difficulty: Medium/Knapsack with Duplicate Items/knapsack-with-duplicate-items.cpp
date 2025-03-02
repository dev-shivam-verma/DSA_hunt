//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<int> prev (capacity + 1, 0);
        vector<int> cur (capacity + 1, 0);
        
        // base case
        for (int cap = wt[0]; cap <= capacity; cap++){
            prev[cap] = (cap/wt[0]) * val[0];
        }
        
        // tabulation with space optemization
        for (int idx = 1; idx < val.size(); idx++){
            for (int cap = 0; cap <= capacity; cap++){
                int notTake = prev[cap];
                int take = 0;
                
                if (cap >= wt[idx]){
                    take = val[idx] + cur[cap - wt[idx]];
                }
                
                cur[cap] = max(take, notTake);
            }
            
            prev = cur;
        }
        
        return prev[capacity];
    }
    
    
    
    
    
    
    
    
    int recursion(int idx, vector<int>& val, vector<int>& wt, int capacity){
        
        if (capacity == 0) return 0;
        if (idx == 0){
            if (capacity >= wt[0]) return (capacity/wt[0]) * val[0];
            return 0;
        }
        
        int notTake = recursion(idx - 1, val, wt, capacity);
        int take = 0;
        
        if (capacity >= wt[idx]){
            take = val[idx] + recursion(idx, val, wt, capacity - wt[idx]);
        }
        
        return max(take, notTake);
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends