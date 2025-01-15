class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        return getSubsets(nums, subset, 0);
    }

    vector<vector<int>> getSubsets(vector<int>& nums, vector<int>& subset, int idx){
        vector<vector<int>> ans;

        if (idx == nums.size()){
            ans.push_back(subset);
            return ans;
        }

        subset.push_back(nums[idx]);
        ans = getSubsets(nums,subset,idx + 1);
        subset.pop_back();

        vector<vector<int>> ans2 = getSubsets(nums,subset, idx + 1); 
        ans.insert(ans.end(), ans2.begin(), ans2.end());

        return ans;
    }
};