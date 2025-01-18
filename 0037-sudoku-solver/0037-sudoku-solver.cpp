class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool solved = false;
        solveHelper(board, 0, 0, solved);
    }


    bool isValid(vector<vector<char>>& board, int row, int col, char element){
        int n = board.size();

        // vertical and horizontal check
        for (int i = 0; i < n; i++){
            if (board[row][i] == element) return false;
            if (board[i][col] == element) return false;
        }

        // determining the subGrid
        int rowStart, rowEnd, colStart, colEnd;

        // determining row range
        if (row < 3){
            rowStart = 0;
            rowEnd = 2;
        } else if(row < 6){
            rowStart = 3;
            rowEnd = 5;
        } else{
            rowStart = 6;
            rowEnd = 8;
        }

        // determining column range
        if (col < 3){
            colStart = 0;
            colEnd = 2;
        } else if (col < 6){
            colStart = 3;
            colEnd = 5;
        } else {
            colStart = 6;
            colEnd = 8;
        }

        for (int r = rowStart; r <= rowEnd; r++){
            for (int c = colStart; c <= colEnd; c++){
                if (board[r][c] == element) return false;
            }
        }

        return true;
    }


    void solveHelper(vector<vector<char>>& board, int row, int col, bool& solved){
        int n = board.size();
        if (row == n){
            solved = true;
            return;
        }

        if (board[row][col] != '.'){
                // moving to next position 
                if (col == 8){
                    solveHelper(board, row + 1, 0, solved);
                } else {
                    solveHelper(board, row, col + 1, solved);
                }
                return;
        } 

        for (char i = '1'; i <= '9'; i++){
            if(isValid(board, row, col, i)){
                board[row][col] = i; 

                if (col == 8){
                    solveHelper(board, row + 1, 0, solved);
                } else {
                    solveHelper(board, row, col + 1, solved);
                }
                if (solved) return;

                board[row][col] = '.';
            } 
        }
    }
};