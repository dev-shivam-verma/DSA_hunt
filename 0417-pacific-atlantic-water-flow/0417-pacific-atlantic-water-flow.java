class Solution {
    boolean[][] dp;
    int[] visited;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;

        dp = new boolean[n * m][2];
        visited = new int[n * m];

        List<List<Integer>> results = new ArrayList<>();

        Queue<int[]> que = new LinkedList<>();

        // for pacific 
        for (int col = 0; col < m; col++) que.add(new int[]{0, col});
        for (int row = 1; row < n; row++) que.add(new int[]{row, 0});

        while (!que.isEmpty()) {
            int[] node = que.poll();
            int i = node[0];
            int j = node[1];

            int index = (i * m) + j;
            visited[index] = 1;
            dp[index][0] = true;

            int[][] dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

            for (int x = 0; x < 4; x++) {
                int ci = i + dir[x][0];
                int cj = j + dir[x][1];

                int cIndex = (ci * m) + cj;

                if (ci >= 0 && cj >= 0 && ci < n && cj < m && heights[i][j] <= heights[ci][cj] && visited[cIndex] != 1) {
                    que.add(new int[]{ci, cj});
                }
            } 
        }

        Arrays.fill(visited, 0);
        // for antlatic 
        for (int col = 0; col < m; col++) que.add(new int[]{n - 1, col});
        for (int row = 1; row < n; row++) que.add(new int[]{row, m - 1});

        while (!que.isEmpty()) {
            int[] node = que.poll();
            int i = node[0];
            int j = node[1];

            int index = (i * m) + j;
            visited[index] = 1;
            dp[index][1] = true;

            int[][] dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

            for (int x = 0; x < 4; x++) {
                int ci = i + dir[x][0];
                int cj = j + dir[x][1];

                int cIndex = (ci * m) + cj;

                if (ci >= 0 && cj >= 0 && ci < n && cj < m && heights[i][j] <= heights[ci][cj] && visited[cIndex] != 1) {
                    que.add(new int[]{ci, cj});
                }
            } 
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = (i * m) + j;
                if (dp[index][0] && dp[index][1]) {
                    results.add(List.of(i, j));
                }
            }
        }

        return results;        
    }
}