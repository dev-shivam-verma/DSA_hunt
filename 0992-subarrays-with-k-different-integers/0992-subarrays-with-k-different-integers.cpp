class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = maxDist(nums, k) - maxDist(nums, k - 1);
        return ans;
    }

    int maxDist(vector<int>& nums, int k){
        int left = 0;
        int ans = 0;
        unordered_map<int, int> m;

        for (int right = 0; right < nums.size(); right++){
            if (m.find(nums[right]) == m.end()){
                m[nums[right]] = 1;
            } else {
                m[nums[right]]++;
            }


            while (m.size() > k){
                if (m[nums[left]] > 1){
                    m[nums[left]]--;
                } else {
                    m.erase(nums[left]);
                }

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};