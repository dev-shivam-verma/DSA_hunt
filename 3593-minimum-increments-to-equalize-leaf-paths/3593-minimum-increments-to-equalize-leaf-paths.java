



class Solution {
    ArrayList<Integer>[] adj;
    int count;
    int[] cost;
    
    
    public int minIncrease(int n, int[][] edges, int[] cost) {
        adj = new ArrayList[n];
        count = 0;
        this.cost = cost;
        
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] edge: edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }

        dfsMax(0, -1);

        return count;
    }


    int dfsMax(int curr, int parent) {
        ArrayList<Integer> leafCosts = new ArrayList<>();

        for (int i: adj[curr]) {
            if (i != parent) {
                leafCosts.add(dfsMax(i, curr));
            }
        }

        if (leafCosts.isEmpty()) return cost[curr];

        int max = Collections.max(leafCosts);

        for (int i: leafCosts) {
            if (i < max) count++;
        }

        return cost[curr] + max;
    }
}