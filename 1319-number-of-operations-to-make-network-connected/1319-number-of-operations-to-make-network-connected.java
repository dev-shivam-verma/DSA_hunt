public class DisjointSet {
    private final int[] size;
    private final int[] parent;
    private final int[] rank;

    public DisjointSet(int n) {
        size = new int[n + 1];
        rank = new int[n + 1];
        parent = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            rank[i] = 1;
            size[i] = 1;
            parent[i] = i;
        }
    }

    public int findUParent(int x) {
        // base case
        if (parent[x] == x) {
            return x;
        }

        int par = findUParent(parent[x]);
        parent[x] = par;
        return par;
    }
    
    public void unionByRank(int x, int y) {
        int upx = findUParent(x);
        int upy = findUParent(y);
        
        if (upx == upy) return;
        
        if  (rank[upx] < rank[upy]) {
            parent[upx] = upy;
        } else if  (rank[upx] > rank[upy]) {
            parent[upy] = upx;
        } else {
            parent[upx] = upy;
            rank[upy]++;
        }
    }

    public void unionBySize(int x, int y) {
        int upx =  findUParent(x);
        int upy =  findUParent(y);

        if (upx == upy) return;
        if (size[upx] < size[upy]) {
            parent[upx] = upy;
            size[upy] += size[upx];
        } else {
            parent[upy] = upx;
            size[upx] += size[upy];
        }
    }
}

class Solution {
    public int makeConnected(int n, int[][] connections) {
        DisjointSet dj = new DisjointSet(n);
        int components = n;
        int extraWires = 0;

        for (int[] connection: connections) {
            int a = connection[0];
            int b = connection[1];

            if (dj.findUParent(a) != dj.findUParent(b)) {
                components--;
                dj.unionBySize(a,b);
            } else {
                extraWires++;
            }
        }


        return extraWires >= components - 1 ? components - 1: -1;
    }
}