//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);
        
        for (int idx = n; idx > 0; idx--){
            for (int lci = 0; lci <= n; lci++){
                if (lci == 0 || arr[lci - 1] < arr[idx - 1]){
                    cur[lci] = 1 + prev[idx];
                } 
                
                cur[lci] = max(cur[lci], prev[lci]);
            }
            prev = cur;
        }
        
        return prev[0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends