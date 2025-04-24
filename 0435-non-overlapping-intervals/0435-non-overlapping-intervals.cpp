class Solution {
public:

    static bool comparator(vector<int> a, vector<int> b){
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), comparator);

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++){
            if (end <= intervals[i][0]) end = intervals[i][1];
            else ans++;
        }
        return ans;
    }
};