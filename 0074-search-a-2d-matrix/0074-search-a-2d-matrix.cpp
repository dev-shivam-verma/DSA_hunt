class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        while (i < matrix.size() && matrix[i][0] <= target) i++;
        i--;
        if (i == -1) return false;
        return binarySearch(matrix[i], target);  
    }

    bool binarySearch(vector<int>& elements, int target){
        int st = 0, en = elements.size() - 1;

        while (st <= en){
            int mid = st + (en - st)/2;

            if (elements[mid] == target) return true; 
            else if (elements[mid] > target) en = mid - 1;
            else st = mid + 1;
        }

        return false;
    }
};