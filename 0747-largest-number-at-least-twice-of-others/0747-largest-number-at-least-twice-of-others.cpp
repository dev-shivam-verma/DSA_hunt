class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int dominant_index = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > nums[dominant_index]){
                dominant_index = i;
            }
        }

        for (int i = 0; i < nums.size(); i++){
            if (i != dominant_index && nums[dominant_index] < nums[i] * 2 ) return -1;
        }
        

        return dominant_index;
    }
};