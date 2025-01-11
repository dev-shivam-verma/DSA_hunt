class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int midx = 0, midy = n-1;

        while (midx >= 0 && midx < m && midy >= 0 && midy < n){
            int mid = matrix[midx][midy];
            if (mid == target) return true;
            else if (mid > target) midy--;
            else midx++;
        }

        return false;
    }
};