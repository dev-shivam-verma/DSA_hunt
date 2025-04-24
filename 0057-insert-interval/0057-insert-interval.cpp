class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        while (i < n && intervals[i][0] < newInterval[0]){
            ans.push_back(intervals[i]); i++;
        }

        bool prevMerge = false;
        int end = newInterval[1];
        if (i != 0 && ans.back()[1] >= newInterval[0]){
            prevMerge = true;
            end = max(end, ans.back()[1]);
        }

        while (i < n && intervals[i][0] <= end){
            end = max(end, intervals[i][1]);
            i++;
        }

        if (prevMerge) ans.back()[1] = end;
        else ans.push_back({newInterval[0], end});

        while (i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};