class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left;
        vector<int> right;

        left.push_back(1);
        for (int i = 1; i < n; i++){
            if (ratings[i - 1] < ratings[i]){
                left.push_back(left.back() + 1);
            } else {
                left.push_back(1);
            }
        }

        right.push_back(1);
        for (int i = n - 2; i >= 0; i--){
            if (ratings[i + 1] < ratings[i]){
                right.push_back(right.back() + 1);
            } else {
                right.push_back(1);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++){
            int leftv = left[i];
            int rightv = right[n - i - 1];
            
            ans += max(leftv, rightv);
        }

        return ans;
    }
};