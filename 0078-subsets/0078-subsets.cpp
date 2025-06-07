class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        int subsets = 1 << n;

        vector<vector<int>> ans;
        for (int i = 0; i < subsets; i++){
            int currpattern = i;
            vector<int> currSet;

            int idx = 0;
            while (currpattern > 0){
                if ((currpattern & 1) == 1){
                    currSet.push_back(nums[idx]);
                }
                currpattern = currpattern >> 1;
                idx++;
            }

            ans.push_back(currSet);

        }

        return ans;
    }

    
};