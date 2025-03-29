class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> positives;
        vector<int> ans;
        stack<int> temp;

        int idx = 0;

        while (idx < asteroids.size()){
            if (asteroids[idx] > 0){
                positives.push(asteroids[idx]);
                idx++;
            } else if(!positives.empty()){
                int rev_ast = abs(asteroids[idx]);

                if (positives.top() > rev_ast) idx++;
                else if (positives.top() < rev_ast) positives.pop();
                else {
                    positives.pop();
                    idx++;
                }
            } else {
                temp.push(asteroids[idx]);
                idx++;
            }
        } 

        for (int i = asteroids.size() - 1; i >= 0; i--){
            int cur = asteroids[i];

            if (!temp.empty() && temp.top() == cur){
                ans.push_back(temp.top());
                temp.pop();
            } else if (!positives.empty() && positives.top() == cur){
                ans.push_back(positives.top());
                positives.pop();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};