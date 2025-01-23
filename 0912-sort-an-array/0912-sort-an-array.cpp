class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void mergeArr(vector<int>& nums, int start, int end, int mid){
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end){
            if (nums[i] > nums[j]){
                temp.push_back(nums[j]);
                j++;
            } else {
                temp.push_back(nums[i]);
                i++;
            }
        }

        //left
        while ( i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        // right
        while ( j <= end){
            temp.push_back(nums[j]);
            j++;
        }

        for (int i = 0; i < temp.size(); i++){
            nums[i + start] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if (start == end){
            return;
        }

        int mid = start + (end - start)/2;

        // first half 
        mergeSort(nums, start, mid );

        // second half
        mergeSort(nums, mid + 1, end);

        mergeArr(nums,start, end, mid);
    }
};