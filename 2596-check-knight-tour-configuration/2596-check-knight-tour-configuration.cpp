class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, 0);
    }

    bool isValid(vector<vector<int>>& grid, int row, int col, int expected){
        int n = grid.size();
        
        // false move
        if (row < 0 || col < 0 || row >= n || col >= n) return false;
        int curr = grid[row][col];
        if (curr != expected) return false;

        // when knigth reaches end
        if (curr == n * n - 1) return true;

        bool a  = isValid(grid, row - 2, col - 1, expected + 1);
        bool b  = isValid(grid, row - 2, col + 1, expected + 1);
        bool c  = isValid(grid, row - 1, col - 2, expected + 1);
        bool d  = isValid(grid, row - 1, col + 2, expected + 1);
        bool e  = isValid(grid, row + 2, col - 1, expected + 1);
        bool f  = isValid(grid, row + 2, col + 1, expected + 1);
        bool g  = isValid(grid, row + 1, col - 2, expected + 1);
        bool h  = isValid(grid, row + 1, col + 2, expected + 1);
    
        return a||b||c||d||e||f||g||h;
    }
};