class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 1){
                sum++;
            }


            if (sum >= goal){

                // for reaching goal
                while (sum > goal && left <= right){
                    if(nums[left] == 1) sum--;
                    left++;
                }
                if (left > right) continue;

                // for trimming zeros
                int temp = left;
                while (nums[temp] == 0 && temp < right){
                    ans++;
                    temp++;
                }         
                ans++;           
            }
        }

        return ans;
    }
};