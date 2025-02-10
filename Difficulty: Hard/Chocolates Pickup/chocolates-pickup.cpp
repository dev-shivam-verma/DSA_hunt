//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
        return recursion(0, 0, m - 1,m,  grid, dp);
    }
    
    
    int recursion(int i, int j1, int j2, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
    int curr = 0;

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

    if (j1 != j2){
        curr += grid[i][j1] + grid[i][j2];
    } else {
        curr += grid[i][j1];
    }

    if (i == grid.size() - 1) return curr;
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e9;

    for (int di = -1; di <= 1; di++){
        for (int dj = -1; dj <= 1; dj++){
            maxi = max(maxi, recursion(i + 1, j1 + di, j2 + dj, m, grid, dp));
        }
    }

    dp[i][j1][j2] = curr + maxi;
    return maxi + curr;
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