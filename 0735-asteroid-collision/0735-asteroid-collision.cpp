class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> positives;
        vector<int> ans;

        int idx = 0;


        while (idx < asteroids.size()){
            if (asteroids[idx] > 0){
                positives.push_back(asteroids[idx]);
                idx++;
            } else if(!positives.empty() && positives.back() > 0){
                int rev_ast = abs(asteroids[idx]);

                if (positives.back() > rev_ast) idx++;
                else if (positives.back() < rev_ast) positives.pop_back();
                else {
                    positives.pop_back();
                    idx++;
                }
            } else {
                positives.push_back(asteroids[idx]);
                idx++;
            }
        } 


        
        return positives;
    }
};