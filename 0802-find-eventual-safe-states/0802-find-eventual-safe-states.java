class Solution {

    public boolean isSafe(int node, int[] visited, int[][] graph) {
    if (visited[node] == 1) return false; // currently in recursion stack ⇒ cycle
    if (visited[node] == 2) return true;  // already determined safe

    visited[node] = 1; // mark as visiting

    for (int nbr : graph[node]) {
        if (!isSafe(nbr, visited, graph)) return false;
    }

    visited[node] = 2; // mark as safe
    return true;
}

public List<Integer> eventualSafeNodes(int[][] graph) {
    List<Integer> ans = new ArrayList<>();
    int[] visited = new int[graph.length];  // shared across all calls

    for (int i = 0; i < graph.length; i++) {
        if (isSafe(i, visited, graph)) {
            ans.add(i);
        }
    }

    return ans;
}

}