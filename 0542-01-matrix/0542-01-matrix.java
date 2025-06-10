class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 1){
                    mat[i][j] = Integer.MAX_VALUE;

                    for (int x = 0; x < m; x++){
                        for (int y = 0; y < n; y++){
                            if (mat[x][y] == 0){
                                int distance = Math.abs(i - x) + Math.abs(j - y);
                                mat[i][j] = Math.min(distance, mat[i][j]);
                            }
                        }
                    }
                }
            }
        }

        return mat;
    }
}