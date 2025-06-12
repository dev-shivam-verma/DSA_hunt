class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();

        f(ans, candidates, target, candidates.length - 1, new ArrayList<Integer>());

        return ans;
    }

    void f(List<List<Integer>> collection, int[] candidates, int target, int idx, List<Integer> subset) {
        if (target == 0) {
            List<Integer> validSubset = new ArrayList<>(subset);
            collection.add(validSubset);
            return;
        }

        if (idx < 0) return;

        // take
        if (candidates[idx] <= target) {
            subset.add(candidates[idx]);    
            f(collection, candidates, target - candidates[idx], idx , subset);
            subset.remove(subset.size() - 1); // backtracking 
        }


        // no take
        f(collection, candidates, target, idx - 1, subset);
    }
}