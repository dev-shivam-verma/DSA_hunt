class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        int[] di = {-1,0,1,0};
        int[] dj = {0,-1,0,1};

        int[][] visited = new int[m][n];
        Queue<List<Integer>> que = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && visited[i][j] == 0){
                    boolean flag = false;

                    for (int x = 0; x < 4; x++) {
                        int dyi = di[x] + i;
                        int dyj = dj[x] + j;

                        if (dyi >= 0 && dyj >= 0 && dyi < m && dyj < n && mat[dyi][dyj] == 0) {
                            flag = true;
                            break;
                        }
                    }

                    if (flag) {
                        List<Integer> loc = new ArrayList<>();
                        loc.add(i);
                        loc.add(j);

                        visited[i][j] = 1;

                        que.add(loc);
                    }
                }
            }
        }

        while (!que.isEmpty()) {
            List<Integer> loc = que.poll();
            int i = loc.get(0);
            int j = loc.get(1);

            for (int x = 0; x < 4; x++) {
                int dyi = di[x] + i;
                int dyj = dj[x] + j;

                if (dyi >= 0 && dyj >= 0 && dyi < m && dyj < n && mat[dyi][dyj] == 1 && visited[dyi][dyj] == 0) {
                    mat[dyi][dyj] = mat[i][j] + 1;
                    visited[dyi][dyj] = 1;
                    
                    List<Integer> dloc = new ArrayList<>();
                    dloc.add(dyi);
                    dloc.add(dyj);

                    que.add(dloc);
                }
                
            }
        }

        

        return mat;
    }
}