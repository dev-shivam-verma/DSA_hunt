class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int subarr = 0;
        int n = nums.size();

        // bruteforce
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i; j < n; j++){
                sum += nums[j];

                if (sum == k) subarr++;
            }
        }

        return subarr;
    }
};