
class DisjointSet {
    int[] size;
    int[] parent;

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

    public List<Integer> numOfIslands(int rows, int cols, int[][] operators) {
        int[][] matrix = new int[rows][cols];
        DisjointSet ds = new DisjointSet(rows * cols);

        int islands = 0;
        List<Integer> result = new ArrayList<>();
        
        for (int[] operator: operators) {
            int x = operator[0];
            int y = operator[1];
            int cell = (x * cols) + y;
            
            if (matrix[x][y] != 1) {
                matrix[x][y] = 1;
                islands++;
                
                int[][] pos = {
                    {-1, 0}, 
                    {0, 1},
                    {1, 0},
                    {0, -1}
                }; 
                
                for (int dir = 0; dir < 4; dir++) {
                    int i = x + pos[dir][0];
                    int j = y + pos[dir][1];
                    int nbrCell = (i * cols) + j;
                    
                    if (i >= 0 && j >= 0 && i < rows && j < cols) // valid cell check
                    {
                        if (matrix[i][j] == 1 && ds.findUPar(cell) != ds.findUPar(nbrCell)) 
                        {
                            islands--;
                            ds.union(cell, nbrCell);
                        }
                    } 
                }
            }
            
            result.add(islands);
        }
        
        return result;
    }
}