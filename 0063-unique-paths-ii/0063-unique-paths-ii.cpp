class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;

        vector<int> temp(n, 0);
        
        // tabulation 
        for (int i = 0; i < m; i++) {
            int prevj = 0;
            for (int j = 0; j < n; j++){
                int count = 0;

                if (obstacleGrid[i][j] != 1){
                    if (j > 0) count += prevj;
                    count += temp[j];

                    if (i == 0 && j == 0) count = 1;
                }

                prevj = count;
                temp[j] = count;
            }
        }

        

        return temp[n - 1];
    }
};