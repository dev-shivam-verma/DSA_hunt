class DisjointSet {
    public int[] size;
    public int[] parent;

    DisjointSet(int n) {
        size = new int[n];
        parent = new int[n];

        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    public int findUPar(int node) {
        if (parent[node] == node) return node;

        // Path compression
        return parent[node] = findUPar(parent[node]);
    }

    public void union(int u, int v) {
        int paru = findUPar(u);
        int parv = findUPar(v);

        if (paru == parv) return;

        // Union by size
        if (size[paru] < size[parv]) {
            parent[paru] = parv;
            size[parv] += size[paru];
        } else {
            parent[parv] = paru;
            size[paru] += size[parv];
        }
    }
}


class Solution {
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n*n);
        int maxSize = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cell = (i * n) + j;

                    int[][] pos = {
                        {-1, 0},
                        {0, 1}, 
                        {1, 0}, 
                        {0, -1}
                    };

                    for (int dir = 0; dir < 4; dir++) {
                        int x = pos[dir][0] + i;
                        int y = pos[dir][1] + j;
                        int nbrCell = (x * n) + y;

                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                            ds.union(cell, nbrCell);
                        }                  
                    }
                }
            }
        } 


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int size = 1;

                    int[][] pos = {
                        {-1, 0},
                        {0, 1}, 
                        {1, 0}, 
                        {0, -1}
                    };

                    List<Integer> cf = new ArrayList<>(); 

                    for (int dir = 0; dir < 4; dir++) {
                        int x = pos[dir][0] + i;
                        int y = pos[dir][1] + j;
                        int nbrCell = (x * n) + y;

                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                            boolean isNew = true;

                            for (int found: cf) {
                                if (ds.findUPar(nbrCell) == ds.findUPar(found)) isNew = false;
                            }

                            if (isNew) {
                                cf.add(nbrCell);
                                size += ds.size[ds.findUPar(nbrCell)];
                            }
                        }                  
                    }

                    maxSize = Math.max(size, maxSize);
                }
            }
        } 



        return maxSize == 0? n * n : maxSize; 
    }
}