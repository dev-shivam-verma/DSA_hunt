class Solution {

    // Function to return length of longest subsequence of consecutive integers.
    public int longestConsecutive(int[] arr) {
        Set<Integer> set = new HashSet<>(); 
        
        int max = 0; 
        for (int num: arr) {
            set.add(num);
            max = Math.max(max, num);
        }
        
        int sum = 0; 
        int maxi = 0 ; 
        
        for (int i = 0; i <= max; i++) {
            if (set.contains(i)) sum++; 
            else sum = 0;
            
            maxi = Math.max(maxi, sum); 
        }
        
        return maxi;
    }
}