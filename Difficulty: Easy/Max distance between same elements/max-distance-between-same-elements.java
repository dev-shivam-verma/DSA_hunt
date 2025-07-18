//{ Driver Code Starts
import java.util.*;
import java.util.Scanner;


// } Driver Code Ends
class Solution {
    public int maxDistance(int[] arr) {
        // Code here
        
        int maxDistance = 0;
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < arr.length; i++){

            // ? Is the element already present in map
            if (map.containsKey(arr[i])){

                // Distance from previous occurance
                int distance = i - map.get(arr[i]);
                maxDistance = Math.max(distance, maxDistance);
            } else map.put(arr[i], i);
        }
        
        
        return maxDistance;
        
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String input = sc.nextLine();
            String[] parts = input.split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maxDistance(arr));
        
System.out.println("~");
}
        sc.close();
    }
}
// } Driver Code Ends
