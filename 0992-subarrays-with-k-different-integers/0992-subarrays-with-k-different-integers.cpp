class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int left = 0;
        set<int> lastOccur;
        unordered_map<int, int> m;

        int ans = 0;

        for (int right = 0; right < nums.size(); right++){
            if (m.find(nums[right]) != m.end()){
                int idx = m[nums[right]];
                lastOccur.erase(idx);
            }
            m[nums[right]] = right;
            lastOccur.insert(right);

            if (m.size() > k){
                int lastIdx = *lastOccur.begin();
                left = lastIdx + 1;
                m.erase(nums[lastIdx]);
                lastOccur.erase(lastIdx);
            }

            if (m.size() == k){
                ans++;
                int lastIdx = *lastOccur.begin();
                ans += lastIdx - left;
            }
        }

        return ans;
    }
};