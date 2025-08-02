class Solution {
    private void dfs(int node, int[] vis, Stack<Integer> stk, ArrayList<ArrayList<Integer>> adj) {
        vis[node] = 1;
        
        for (int nbr: adj.get(node)) {
            if (vis[nbr] != 1) {
                dfs(nbr, vis, stk, adj);
            }
        }
        
        stk.push(node);
    }
    
    private void dfs2(int node, int[] vis, ArrayList<Integer>[] adj) {
        vis[node] = 1; 
        
        for (int nbr: adj[node]) {
            if (vis[nbr] != 1) {
                dfs2(nbr, vis, adj);
            }
        }
    }
    
    
    public int kosaraju(ArrayList<ArrayList<Integer>> adj) {
        int n = adj.size();
        int[] vis = new int[n];
        Stack<Integer> stk = new Stack<>();
        
        
        // step one, count the time of discovery
        for (int i = 0; i < n; i++) {
            if (vis[i] != 1) {
                dfs(i, vis, stk, adj);
            }
        }
        
        
        // step 2: reverse the edges
        ArrayList<Integer>[] adjT = new ArrayList[n];
        
        for (int i = 0; i < n; i++) adjT[i] = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            for (int nbr: adj.get(i)) {
                adjT[nbr].add(i);
            }
        }
        
        
        Arrays.fill(vis, 0);
        int count = 0;
        // step 3, find the sccs
        while(!stk.isEmpty()) {
            int node = stk.pop();
            
            if (vis[node] != 1) {
                count++;
                dfs2(node, vis, adjT);
            }
        }
        
        return count;
    }
}