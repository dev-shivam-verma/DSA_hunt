//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
        
        // base case 
        for (int j1 = 0; j1 < m; j1++){
            for (int j2 = 0; j2 < m; j2++){
                
                int curr = 0;
                if (j1 != j2){
                    curr += grid[n-1][j1] + grid[n-1][j2];
                } else {
                    curr += grid[n-1][j1];
                }
            
                dp[n-1][j1][j2] = curr;
            }
        }
        
        for (int i = n-2; i >= 0; i--){
            for (int j1 = 0; j1 < m; j1++){
                for (int j2 = 0; j2 < m; j2++){
                    int curr = 0;
                    if (j1 != j2){
                        curr += grid[i][j1] + grid[i][j2];
                    } else {
                        curr += grid[i][j1];
                    }
                    
                    dp[i][j1][j2] = INT_MIN;
                    
                    for (int di = -1; di <= 1; di++){
                        for (int dj = -1; dj <= 1; dj++){
                            int jdi = j1 + di;
                            int jdj = j2 + dj;
                            
                            if (jdi >= 0 && jdi < m && jdj >= 0 && jdj < m){
                                dp[i][j1][j2] = max(dp[i][j1][j2], dp[i + 1][jdi][jdj] + curr);
                            }
                        }
                    }
                }
            }
        }
        
        
        return dp[0][0][m - 1];
    }
    
    
    
    
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends