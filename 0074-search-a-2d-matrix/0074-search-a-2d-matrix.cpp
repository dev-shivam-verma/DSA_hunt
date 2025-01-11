class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0, end = matrix.size() - 1;
        int ridx = -1;

        while (st <= end){
            int mid = st + (end - st)/2;

            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) end = mid - 1;
            else {
                ridx = mid;
                st = mid + 1;
            }
        }
        return ridx == -1 ? false : binarySearch(matrix[ridx], target);
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