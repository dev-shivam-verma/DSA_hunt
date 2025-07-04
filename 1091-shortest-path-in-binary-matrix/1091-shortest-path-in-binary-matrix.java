class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) return -1;

        int n = grid.length;
        int m = grid[0].length;        
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[]{0,0,1});

        int[][] directions = {
            {-1,0},
            {-1,1}, 
            {0,1},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {-1,-1}
        };

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            if (cur[0] == n - 1 && cur[1] == m - 1) return cur[2];
            grid[cur[0]][cur[1]] = 1;

            for (int[] direction: directions) {
                int i = cur[0] + direction[0];
                int j = cur[1] + direction[1];

                // validation 
                if (i < 0 || j < 0 || i >= n || j >= m) continue;
                if (grid[i][j] == 0) {
                    que.add(new int[]{i, j, cur[2] + 1});
                }
            }
        }

        return -1;
    }
}