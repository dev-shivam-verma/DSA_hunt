class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int sum = 0;
        for (int i: arr) sum += i;
        int target = sum;
        
        vector<int> prev(target + 1, 0);
        vector<int> cur(target + 1, 0);
        
        // base case
        prev[0] = 1; 
        prev[arr[0]]++;
        
        for (int idx = 1; idx < arr.size(); idx++){
            for (int tar = 0; tar <= target; tar++){
                int notTake = prev[tar];
                int take = 0;
                
                if (tar >= arr[idx]){
                    take = prev[tar - arr[idx]];
                }
                
                cur[tar] = take + notTake;
            }
            prev = cur;
        }
        
        int count = 0;
        
        for (int i = 0; i <= target; i++){
            
            if (sum - 2 * i == d){
                count += prev[i];
            }
        }
        
        return count;
    }

};