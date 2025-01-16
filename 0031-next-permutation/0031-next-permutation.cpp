class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;

        // finding end of decreasing order
        while (i > 0){
            if ( nums[i] > nums[i - 1] ){
                break;
            }
            i--;
        }

        if (i == 0){
            reverse(nums.begin(), nums.end());
        } else {

            int p1 = i-1;
            i = n-1;
            // finding the lowest number greater to nums[p1]
            while (i > p1){
                if (nums[i] > nums[p1]) break;
                i--;
            }

            // swapping and reversing to get next lexicographically greater permutation
            swap(nums[i], nums[p1]);
            reverse(nums.begin() + p1 + 1, nums.end());
        }
    }
    
};