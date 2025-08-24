// User function Template for Java

class Solution {
    public ArrayList<Integer> getLIS(int arr[]) {
        // Code here
        int n = arr.length;
        
        int[] dp = new int[n];
        int[] hash = new int[n];
        
        for (int i = 0; i < n; i++) {
            dp[i] = 1; 
            hash[i] = i;
        }
        
        int tail = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (1 + dp[j] > dp[i] && arr[i] > arr[j]) {
                    hash[i] = j;
                    dp[i] = 1 + dp[j];
                    
                    if (dp[tail] < dp[i]) {
                        tail = i;
                    }
                }
            }
        }
        
        
        
        ArrayList<Integer> lis = new ArrayList<Integer>();
        while (hash[tail] != tail) {
            lis.add(arr[tail]);
            tail = hash[tail];
        }
        lis.add(arr[tail]);
        Collections.reverse(lis);
        
        return lis;
    }
}
