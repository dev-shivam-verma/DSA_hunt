class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        helper(candidates, 0, 0, target, combination, ans);

        return ans;
    }

    void helper(vector<int> nums, int currIdx, int currSum,int target, vector<int> combination, vector<vector<int>>& ans ){

        if (currSum == target){
            ans.push_back(combination);
            return;
        } 
        if (currIdx == nums.size() || currSum > target) return;
        

        // choice 1 choosing same number
        combination.push_back(nums[currIdx]);
        helper(nums, currIdx, currSum + nums[currIdx], target, combination, ans);

        // deleting the element at backtracking
        combination.pop_back();
        // choice 2 chosing next from array
        helper(nums, ++currIdx, currSum, target, combination, ans);

    }
};