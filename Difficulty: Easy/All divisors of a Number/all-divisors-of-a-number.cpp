//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        list<int> ans;
        
        for (int i = 1; i <= sqrt(n); i++){
            
            if (n % i == 0){
                cout<<i<<" ";
                if (n/i != i){
                    ans.push_front(n/i);
                }
            }
        }
        
        for (int i: ans){
            cout<<i<<" ";
        }
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends