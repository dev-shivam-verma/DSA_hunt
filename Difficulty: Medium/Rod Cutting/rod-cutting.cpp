//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);
        
        // base case
        for (int len = 0; len <= n; len++){
            prev[len] = len * price[0];
        }
        
        // tabulation with space optimization
        for (int idx = 1; idx < n; idx++){
            for (int len = 0; len <= n; len++){
                int notTake = prev[len];
                int take = 0;
                
                if (len >= idx + 1){
                    take = price[idx] + cur[len - idx - 1];
                }
                
                cur[len] = max(take, notTake);
            }
            
            prev = cur;
        }
        
        return prev[n];
    }
    
    int recursion(int idx, int length, vector<int> &price){
        
        if (length == 0) return 0;
        if (idx == 0){
            return length * price[0];
        }
        
        int notTake = recursion(idx - 1, length, price);
        int take = 0;
        
        if (length >= idx + 1){
            take = price[idx] + recursion(idx, length - idx - 1, price);
        }
        
        return max(notTake, take);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends