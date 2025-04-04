class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int ans = 0;
        list<int> zeros;
        

        for (int j = 0; j<nums.size(); j++){
            if (nums[j] == 0 ){
                zeros.push_back(j);
                if (k > 0){
                    k--;
                } else {
                    i = zeros.front() + 1;
                    zeros.pop_front();
                }                    
            }

            int length = j - i + 1;
            ans = max(length, ans);
        }

        return ans;
    }
};