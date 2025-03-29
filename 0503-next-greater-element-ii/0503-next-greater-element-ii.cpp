class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> stk;

        for (int i = nums.size() - 1; i >= 0; i--){
            while (!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }

            if (!stk.empty()){
                ans[i] = stk.top();
            }
            
            stk.push(nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--){
            while (!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }

            if (!stk.empty()){
                ans[i] = stk.top();
            }
            
            stk.push(nums[i]);
        }

        return ans;
    }
};