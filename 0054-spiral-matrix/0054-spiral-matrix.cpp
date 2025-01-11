class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int xStart = 0, yStart = 0;
        int xEnd = matrix[0].size() - 1, yEnd = matrix.size() - 1;
        vector<int> result = {};

        while (xStart <= xEnd && yStart <= yEnd){

            // Top lane
            for (int i = xStart; i <= xEnd; i++){
                result.push_back(matrix[yStart][i]);
            }

            // Right lane
            for (int i = yStart + 1; i <= yEnd; i++){
                result.push_back(matrix[i][xEnd]);
            }

            // Bottom lane 
            for (int i = xEnd - 1; i >= xStart; i--){
                if ( yStart != yEnd) result.push_back(matrix[yEnd][i]);
            }

            // Left lane
            for (int i = yEnd - 1; i > yStart; i--){
                if ( xStart != xEnd) result.push_back(matrix[i][xStart]);
            }

            // Re-adjusting the boundries 
            xStart++; yStart++;
            xEnd--; yEnd--;
        }

        return result;
    }
};