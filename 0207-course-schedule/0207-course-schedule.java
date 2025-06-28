class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indeg = new int[numCourses];
        ArrayList<Integer>[] adj = new ArrayList[numCourses];
        Stack<Integer> stk = new Stack<>();   


        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList<Integer>();
        }

        for (var edge: prerequisites) {
            indeg[edge[1]]++;
            adj[edge[0]].add(edge[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) stk.push(i);
        }

        int count = 0;
        while (!stk.isEmpty()) {
            int cur = stk.pop();

            indeg[cur] = -1;
            count++;

            for (int nbr: adj[cur]) {
                indeg[nbr]--;

                if (indeg[nbr] == 0) stk.push(nbr);
            }
        }

        if (count != numCourses) return false;

        return true;
    }
}