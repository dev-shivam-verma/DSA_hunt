
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < k; i++){
            ans = nums.front();
            pop_heap(nums.begin(), nums.begin() + n - i);
        }

        return ans;
    }
};