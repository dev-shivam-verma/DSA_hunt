class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int[] visited = new int[n];
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                provinces++;

                Stack<Integer> stk = new Stack<>();
                stk.push(i);

                while (!stk.isEmpty()) {
                    int cur = stk.pop();
                    visited[cur] = 1;

                    // DFS to track the entire provice
                    for (int j = 0; j < n; j++){
                        if (isConnected[cur][j] == 1 && visited[j] == 0){
                            stk.push(j);
                        }
                    }
                }

            }
        }

        return provinces;
    }
}