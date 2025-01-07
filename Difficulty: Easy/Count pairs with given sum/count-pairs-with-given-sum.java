//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
class Solution {

    int countPairs(int arr[], int target) {
        // Your code here
        int res = 0;
        
        Map<Integer, Integer> map = new HashMap<>();
        
        
        for (int i: arr){
            
            // ? Complement present
            if (map.containsKey(target - i)){
                
                // Increment pair count
                int frequency = map.get(target - i);
                res += frequency;
            } 
            
            if (map.containsKey(i)){
                int frequency = map.get(i);
                map.put(i, ++frequency);
            } else {
                map.put(i, 1);
            }
        }
        
        return res;
    }
}

//{ Driver Code Starts.

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String line = read.readLine().trim();
            String[] numsStr = line.split(" ");
            int[] nums = new int[numsStr.length];
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }

            int target = Integer.parseInt(read.readLine());

            Solution obj = new Solution();

            System.out.println(obj.countPairs(nums, target));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends