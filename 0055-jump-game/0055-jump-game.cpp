class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reachable(nums.size(), false);
        reachable[0] = true;
        for (int i = 0; i < nums.size(); i++){
            if (reachable[i]){
                for (int j = 1; j <= nums[i]; j++){
                    if (j + i < nums.size()){
                        reachable[j + i] = true;
                    }
                }
            }
        }


        return reachable[nums.size() - 1];
    }
};