class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();

        f(9, k, n, new ArrayList<Integer>(), ans);
        return ans;
    }


    void f (int num, int k, int target, List<Integer> subset, List<List<Integer>> ans) {
        // base case
        if (k == 0 && target == 0) {
            List<Integer> subsetCopy = new ArrayList<>(subset);
            ans.add(subsetCopy);
            return;
        } 

        // base casee
        if (k == 0 || target == 0 || num == 0) return;

        // take 
        if (num <= target) {
            subset.add(num);
            f (num - 1, k - 1, target - num, subset, ans);
            subset.remove(subset.size() - 1); // backtrack
        }

        // not take
        f(num - 1, k, target, subset, ans);
    }
}