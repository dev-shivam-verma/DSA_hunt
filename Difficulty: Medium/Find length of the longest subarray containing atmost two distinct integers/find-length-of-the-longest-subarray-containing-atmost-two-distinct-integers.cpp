//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int, int> m;
        int i = 0;
        int ans = 0;
        
        for (int j = 0; j < arr.size(); j++){
            if (m.find(arr[j]) == m.end()){
                m[arr[j]] = 1;
            } else {
                m[arr[j]]++;
            }
            
            while(m.size() > 2){
                if (m[arr[i]] > 1){
                    m[arr[i]]--;
                } else {
                    m.erase(arr[i]);
                }
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends