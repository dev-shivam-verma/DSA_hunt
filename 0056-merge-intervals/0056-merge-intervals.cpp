class Solution {
public:

    static bool comparator(vector<int> a, vector<int> b){
        return a < b;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comparator);

        ans.push_back(intervals[0]);
        int i = 1, n = intervals.size();
        while(i < n){
            while (i < n && ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]); i++;
            } 
            if (i >= n) break;

            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            i++;
        }

        return ans;
    }
};