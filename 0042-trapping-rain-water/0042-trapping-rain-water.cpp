class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        stack<int> forw; 
        stack<int> prev;
        vector<int> biggestForw(n,0);

        forw.push(height[n - 1]);
        biggestForw[n - 1] = height[n-1];

        for (int i = n - 2; i >= 0; i--) {
            while (!forw.empty() && forw.top() < height[i]) forw.pop();   
            biggestForw[i] = forw.empty()? height[i]: forw.top();
            if (forw.empty() || forw.top() < height[i]) forw.push(height[i]);
            
        }

        prev.push(height[0]);

        int water = 0; 

        for (int i = 0; i < n; i++) {
            while(!prev.empty() && prev.top() < height[i]) prev.pop();
            int prevLarge = prev.empty()? height[i]: prev.top();
            int level = prevLarge > biggestForw[i]? biggestForw[i]: prevLarge;

            if (level > height[i]) water += level - height[i];

            if (prev.empty() || prev.top() < height[i]) prev.push(height[i]);
        }


        return water;
    }
};