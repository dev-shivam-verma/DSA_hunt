class Solution {
    void bfs(int i, int j, char[][] board, boolean[][] visited) {
        int m = board.length;
        int n = board[0].length;

        visited[i][j] = true;
        int[] di = {-1,0,1,0};
        int[] dj = {0,-1,0,1};

        for (int x = 0; x < 4; x++) {
            int dyi = di[x] + i;
            int dyj = dj[x] + j;


            if (dyi >= 0 && dyj >= 0 && dyi < m && dyj < n && !visited[dyi][dyj] && board[dyi][dyj] == 'O') {
                bfs(dyi, dyj, board, visited);
            }
        }        
    }

    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;

        boolean[][] visited = new boolean[m][n];
        

        // rows 
        for (int j = 0; j < n; j++) {

            // first row
            if (!visited[0][j] && board[0][j] == 'O') {
                bfs(0,j, board, visited);
            }

            // last row 
            if (!visited[m-1][j] && board[m-1][j] == 'O') {
                bfs(m-1,j, board, visited);
            }
        }

        // columns
        for (int i = 0; i < m; i++) {

            // first column 
            if (!visited[i][0] && board[i][0] == 'O') {
                bfs(i, 0, board, visited);
            }

            // last column
            if (!visited[i][n-1] && board[i][n-1] == 'O') {
                bfs(i, n-1, board, visited);
            }
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
}