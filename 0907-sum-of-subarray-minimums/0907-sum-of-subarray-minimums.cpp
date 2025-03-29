class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> dp(n, 0);

        long long int ans = 0;
        

        for (int i = 0; i < n; i++){
            while (!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }

            int prevMinIdx = -1;
            if (!stk.empty()){
                prevMinIdx = stk.top();
            }

            dp[i] += ((i + 1) - (prevMinIdx + 1)) * arr[i];
            if (prevMinIdx >= 0) dp[i] += dp[prevMinIdx];

            ans = (ans + dp[i]) % (int)(1e9 + 7);
            stk.push(i);
        }

        return ans;
    }
};