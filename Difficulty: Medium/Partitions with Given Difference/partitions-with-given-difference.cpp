//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = 0;
        for (int i: arr) sum += i;
        int target = sum;
        
        vector<int> prev(target + 1, 0);
        vector<int> cur(target + 1, 0);
        
        // base case
        prev[0] = 1; 
        prev[arr[0]]++;
        
        for (int idx = 1; idx < arr.size(); idx++){
            for (int tar = 0; tar <= target; tar++){
                int notTake = prev[tar];
                int take = 0;
                
                if (tar >= arr[idx]){
                    take = prev[tar - arr[idx]];
                }
                
                cur[tar] = take + notTake;
            }
            prev = cur;
        }
        
        int count = 0;
        
        for (int i = 0; i <= target; i++){
            int s1 = i; 
            int s2 = sum - i;
            
            if (s1 >= s2 && s1 - s2 == d){
                count += prev[i];
            }
        }
        
        return count;
    }
    
    
    
    
    
    
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends