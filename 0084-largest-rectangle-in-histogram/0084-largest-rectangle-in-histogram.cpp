class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> dpForw(n, n);
        vector<int> dpPrev(n, -1);

        stack<int> minForw;
        stack<int> minPrev;

        for (int i = 1; i <= n; i++){
            while (!minPrev.empty() && heights[minPrev.top()] >= heights[i -1]){
                minPrev.pop();
            }

            while (!minForw.empty() && heights[minForw.top()] >= heights[n - i]){
                minForw.pop();
            }

            if (!minPrev.empty()){
                dpPrev[i - 1] = minPrev.top();
            }
            if (!minForw.empty()){
                dpForw[n - i] = minForw.top();
            }


            minPrev.push(i - 1);
            minForw.push(n - i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++){
            int prevBlocks = i - (dpPrev[i] + 1);
            int forwBlocks = dpForw[i] - i;

            int width = prevBlocks + forwBlocks;
            int area = heights[i] * width;

            ans = max(ans, area);
        }


        return ans;
    }
};