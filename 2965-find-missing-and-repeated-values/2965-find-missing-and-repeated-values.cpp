class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> result(2,0);
        int n = grid.size();
        int sum = 0;
        vector<int> arr(n*n, 0);



        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int element = grid[i][j];
                arr[element - 1]++;

                sum += element;
                if (arr[element - 1] == 2) result[0] = element;
            }
        }        

        int sq = n * n;
        int actualSum = sq *(sq + 1)/2;
        
        // missing 
        result[1] = actualSum + result[0] - sum;

        return result;
    }
};