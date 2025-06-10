class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        int m = image.length;
        int n = image[0].length;

        Queue<List<Integer>> que = new LinkedList<>();
        int ogColor = image[sr][sc];

        

        List<Integer> start = new ArrayList<>();
        start.add(sr);
        start.add(sc);

        que.add(start);
        int[] di = {-1, 0, 1, 0};
        int[] dj = {0, -1, 0, 1};

        while (!que.isEmpty()) {
            List<Integer> cur = que.poll();
            int i = cur.get(0);
            int j = cur.get(1);

            image[i][j] = color;

            for (int x = 0; x < 4; x++){
                int dyi = i + di[x];
                int dyj = j + dj[x];

                if (dyi >= 0 && dyj >= 0 && dyi < m && dyj < n && image[dyi][dyj] == ogColor) {
                    List<Integer> dloc = new ArrayList<>();
                    dloc.add(dyi);
                    dloc.add(dyj);
                    que.add(dloc);
                }
            }
        }

        return image;
    }
}