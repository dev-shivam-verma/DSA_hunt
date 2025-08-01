class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int[][] visited = new int[n][n];

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a,b) -> a[2] - b[2]
        );

        visited[0][0] = 1;
        pq.add(new int[]{0,0,grid[0][0]});

        int result = 0;
        while (!pq.isEmpty()) {
            int[] node = pq.poll();
            int x = node[0];
            int y = node[1];
            int time = node[2];

            if (x == n - 1 && y == n - 1) {
                result = time;
                break;
            }

            int[][] pos = {
                {-1, 0}, 
                {0, 1}, 
                {1, 0}, 
                {0, -1}
            };
            for (int dir = 0; dir < 4; dir++) {
                int i = x + pos[dir][0];
                int j = y + pos[dir][1];

                if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] != 1) {
                    visited[i][j] = 1;
                    int nxtTime = time < grid[i][j] ? grid[i][j] : time;
                    pq.add(new int[] {i, j, nxtTime});
                }
            }
        } 

        return result;
    }
}