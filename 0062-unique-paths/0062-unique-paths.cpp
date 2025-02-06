class Solution {


public:
    int uniquePaths(int m, int n) {
        vector<int> temp(n, 0);

        // tabulation
        for (int i = 0; i < m; i++){

            int prevj = 1;

            for (int j = 0; j < n; j++){
                int ways = 0;

                ways += prevj;
                if (j > 0) ways += temp[j];

                prevj = ways;
                temp[j] = ways;
            }
        }

        return temp[n - 1];
    }


    
};