class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {};

        for ( int i = 0; i < numRows; i++){
            result.push_back({});
            for (int j = 0; j <= i; j++){
                if (j == 0 || j == i) result[i].push_back(1);
                else {
                    int val = result[i - 1][j - 1] + result[i - 1][j];
                    result[i].push_back(val);
                }
            }
        }

        return result; 
    }
};