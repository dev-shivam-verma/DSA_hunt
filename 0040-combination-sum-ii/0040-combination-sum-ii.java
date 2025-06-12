class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(candidates);

        f(ans, candidates, target, 0, candidates.length, new ArrayList<Integer>());

        return ans;
    }

    void f(List<List<Integer>> collection, int[] candidates, int target, int idx,int n, List<Integer> subset) {
        if (target == 0) {
            List<Integer> validSubset = new ArrayList<>(subset);
            collection.add(validSubset);
            return;
        }

        if (idx >= n) return;

        // take
        if (candidates[idx] <= target) {
            subset.add(candidates[idx]);    
            f(collection, candidates, target - candidates[idx], idx + 1, n , subset);
            subset.remove(subset.size() - 1); // backtracking 
        }

        while (idx + 1 < n && candidates[idx] == candidates[idx + 1]) idx++;
        // no take
        f(collection, candidates, target, idx + 1, n, subset);
    }
}