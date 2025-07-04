class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        int minEffort = Integer.MAX_VALUE;

        PriorityQueue<int[]> que = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        int[][] effort = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                effort[i][j] = Integer.MAX_VALUE;
            }
        }

        que.add(new int[] {0,0,0});
        int[][] dirs = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };
        
        while (!que.isEmpty()) {
            int[] cur = que.poll();

            if (cur[0] == n-1 && cur[1] == m - 1) return cur[2];
            for (int[] dir: dirs) {
                int i = cur[0] + dir[0];
                int j = cur[1] + dir[1];

                // validation 
                if (i < 0 || j < 0 || i >= n || j >= m) continue;

                int curEffort = Math.abs(heights[cur[0]][cur[1]] - heights[i][j]);
                int maxEffort = Math.max(curEffort, cur[2]);

                if (maxEffort < effort[i][j]) {
                    effort[i][j] = maxEffort;
                    que.add(new int[]{i, j, maxEffort});
                }

            }
        }

        return -1;
    }

    
}