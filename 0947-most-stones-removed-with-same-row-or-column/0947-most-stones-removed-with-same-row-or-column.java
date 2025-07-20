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
    public int removeStones(int[][] stones) {
        int n = stones.length;
        int components = n;
        DisjointSet ds = new DisjointSet(n);
        Map<Integer, Integer> rows = new HashMap<>();
        Map<Integer, Integer> cols = new HashMap<>();

        int idx = 0;
        for (int[] stone: stones) {
            int x = stone[0];
            int y = stone[1];

            if (rows.containsKey(x)) {
                components--;
                ds.unionBySize(idx, rows.get(x));
            } else {
                rows.put(x, idx);
            }

            if (cols.containsKey(y)) {
                int friend = cols.get(y);
                if (ds.findUParent(idx) != ds.findUParent(friend)) {
                    components--;
                    ds.unionBySize(idx, friend);
                }
            } else {
                cols.put(y, idx);
            }


            idx++;
        } 

        return n - components;
    }
}