class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> stk;
        vector<int> ans;
        unordered_map<int,int> map;
        
        for (int i = nums2.size() - 1; i >= 0; i--){
            while (!stk.empty() && stk.top() <= nums2[i]){
                stk.pop();
            }

            if (stk.empty()){
                map[nums2[i]] = -1;
            } else {
                map[nums2[i]] = stk.top();
            }

            stk.push(nums2[i]);
        }

        for (int i: nums1){
            ans.push_back(map[i]);
        }

        
        return ans;
    }
};