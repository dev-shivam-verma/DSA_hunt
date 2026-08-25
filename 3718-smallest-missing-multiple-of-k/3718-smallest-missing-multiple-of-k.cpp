class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }

        int i = 1;
        while(true) {
            if (set.find(i * k) == set.end()) return i*k;

            i++;
        }


        return 0;
    }
};