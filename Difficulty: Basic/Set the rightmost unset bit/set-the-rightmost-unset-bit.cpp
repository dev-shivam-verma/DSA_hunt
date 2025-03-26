//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        
        int tracer = 1;
        while(true){
            if ((n & tracer) == 0){
                return n|tracer;
            }
            
            tracer = tracer << 1;
        }
        
        return n|2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends