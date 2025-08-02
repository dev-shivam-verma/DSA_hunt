class Solution {
    private int[] vis; 
    private int[] dis;
    private int[] low;
    private int[] mark;
    private int time;
    private ArrayList<ArrayList<Integer>> adj;
    
    public void dfs(int node, int parent) {
        vis[node] = 1;
        dis[node] = time;
        low[node] = time;
        time++;
        
        int child = 0;
        for (int nbr: adj.get(node)) {
            if (nbr == parent) continue;

            
            if (vis[nbr] == -1) {
                child++;
                dfs(nbr, node);
                
                low[node] = Math.min(low[node], low[nbr]);
                
                if (low[nbr] >= dis[node] && parent != -1) mark[node] = 1;
            } else {
                low[node] = Math.min(low[node], dis[nbr]);
            }
        }
        
        if (parent == -1 && child > 1) mark[node] = 1;
        
    }
    
    public ArrayList<Integer> articulationPoints(int V,
                                                 ArrayList<ArrayList<Integer>> adj) {
        vis = new int[V];
        dis = new int[V];
        low = new int[V];
        mark = new int[V];
        time = 0;
        this.adj = adj;
        
        Arrays.fill(vis, -1);
        dfs(0, -1);
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) result.add(i);
        }
        
        if (result.size() == 0) return new ArrayList(List.of(-1));
        return result;
    }
}