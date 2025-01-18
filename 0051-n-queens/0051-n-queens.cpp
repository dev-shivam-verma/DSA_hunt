class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        int temp = n;
        string row = "";
        while (temp--){
            row += ".";
        }
        vector<string> board(n, row);

        placeQueen(board, 0, n, ans); 

        return ans;
    }

    bool isSafe(vector<string> board, int row, int col, int size){
        for (int i = row - 1; i >= 0; i--){
            int rowdiff = row - i;
            if (col - rowdiff >= 0){
                if (board[i][col - rowdiff] == 'Q') return false;
            }
            if (col + rowdiff < size){
                if (board[i][col + rowdiff] == 'Q') return false;
            }
            if (board[i][col] == 'Q') return false;
        }

        return true;
    }

    void placeQueen(vector<string> board, int row, int size, vector<vector<string>>& ans){
        if (row == size){
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < size; i++){
            if (isSafe(board, row, i, size)){
                board[row][i] = 'Q';

                placeQueen(board, row + 1, size, ans);

                board[row][i] = '.';
            }
        }
    }
};