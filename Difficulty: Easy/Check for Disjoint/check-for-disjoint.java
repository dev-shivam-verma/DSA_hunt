//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine().trim());

        Solution ob = new Solution();

        while (testCases-- > 0) {
            // Read the first array from input line
            String[] input1 = br.readLine().trim().split(" ");
            int[] arr = new int[input1.length];
            for (int i = 0; i < input1.length; i++) {
                arr[i] = Integer.parseInt(input1[i]);
            }

            // Read the second array from input line
            String[] input2 = br.readLine().trim().split(" ");
            int[] brr = new int[input2.length];
            for (int i = 0; i < input2.length; i++) {
                brr[i] = Integer.parseInt(input2[i]);
            }

            // Invoke the function and print the result
            boolean result = ob.areDisjoint(arr, brr);
            System.out.println(result ? "true" : "false");
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public boolean areDisjoint(int[] a, int[] b) {
        // code here
        
        Set<Integer> set = new HashSet<>();
        for (int i: a){
            set.add(i);
        }
        for (int i: b){
            if (set.contains(i)) return false;
        }
        
        return true;
        
    }
}