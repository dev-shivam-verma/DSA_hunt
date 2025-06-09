class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<List<Integer>> que = new LinkedList<>();
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];

        int ones = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) ones++;
                else if (grid[i][j] == 2) {
                    List<Integer> loc = new ArrayList<>();
                    loc.add(i);
                    loc.add(j);
                    loc.add(0);

                    visited[i][j] = 2;
                    
                    que.add(loc);
                }
            }
        }


        int time = 0;
        int[] di = {-1, 0, +1, 0};
        int[] dj = {0, -1, 0, +1};

        while (!que.isEmpty()){
            List<Integer> loc = que.poll();
            int i = loc.get(0);
            int j = loc.get(1);
            int t = loc.get(2);

            for (int x = 0; x < 4; x++){
                int dyi = i + di[x];
                int dyj = j + dj[x];

                if (dyi >= 0 && dyj >= 0 && dyi < m && dyj < n && visited[dyi][dyj] != 2 && grid[dyi][dyj] == 1){
                    ones--;
                    visited[dyi][dyj] = 2;

                    List<Integer> dloc = new ArrayList<>();
                    dloc.add(dyi);
                    dloc.add(dyj);
                    dloc.add(t + 1);

                    time = t + 1;

                    que.add(dloc);
                }
            }
        }

        return ones == 0? time: -1; 
    }
}