class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0; 
        int j = height.size() - 1;
        
        while (i < j){
            int area = (j-i) * (height[i] < height[j]? height[i]: height[j]);

            if (area > max) max = area;

            if (height[i] < height[j]) i++;
            else j--;
        }


        return max;
    }
};