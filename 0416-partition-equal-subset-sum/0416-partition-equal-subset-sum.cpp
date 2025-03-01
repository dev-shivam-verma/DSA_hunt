class Solution {
public:



    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i: nums) sum += i;
        if (sum % 2 != 0) return false;
        int target = sum/2;

        vector<bool> prev(target + 1, false);
        vector<bool> cur(target + 1, false);
        

        if (nums[0] <= target){
            prev[nums[0]] = true;
        }
        prev[0] = true;

        // tabulation with space optemization 
        for (int idx = 1; idx < nums.size(); idx++){
            for (int tar = 0; tar <= target; tar++){
                bool notTaken = prev[tar];
                bool taken = false;
                if (tar - nums[idx] >= 0){
                    taken = prev[tar - nums[idx]];
                }

                cur[tar] = taken || notTaken;
            }

            prev = cur;
        }

        return prev[target];
    }


    
};