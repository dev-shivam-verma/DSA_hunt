class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n + 1, 0);
        vector<int> cur(n + 1, 0);

        // tabulation with space optemization
        for(int idx = n; idx > 0; idx--){
            for (int lci = 0; lci <= n; lci++){
                int take = 0;
                if (lci == 0 || nums[lci - 1] < nums[idx - 1]){
                    take = 1 + prev[idx];
                } 

                int notTake = prev[lci];
                cur[lci] = max(take, notTake);
            }

            prev = cur;
        }

        return prev[0];
    }

    int f(int idx, int lci, vector<int>& nums){
        if (idx > nums.size()) return 0;

        // take
        int take = 0;
        if (lci == 0 || nums[lci - 1] < nums[idx - 1]){
            take = 1 + f(idx + 1, idx, nums);
        }

        // not take
        int notTake = f(idx + 1, lci, nums);

        return max(take, notTake);
    }

};