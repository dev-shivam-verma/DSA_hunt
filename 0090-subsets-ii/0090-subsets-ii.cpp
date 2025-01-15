class Solution {
public:


    void getsubset(vector<int>& nums, vector<int> subset, int i, vector<vector<int>>& ans){

        if (i == nums.size()){
            ans.push_back({subset});
            return;
        }

        subset.push_back(nums[i]);

        // including current element
        getsubset(nums,subset,i + 1, ans);

        
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        //excluding current element
        subset.pop_back();
        getsubset(nums,subset, i + 1, ans);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        getsubset(nums, subset, 0, ans);


        return ans;
    }
};