class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        f(ans, 0, 0, new StringBuilder(), n);

        return ans;
    }


     public void f(List<String> ansList, int l, int r, StringBuilder ans, int n) {
        if (l == n && r == n) {
            ansList.add(ans.toString());
            return;
        }

        if (l < n) {
            ans.append('(');
            f(ansList, l + 1, r, ans, n);
            ans.deleteCharAt(ans.length() - 1); // backtrack
        }

        if (r < l) {
            ans.append(')');
            f(ansList, l, r + 1, ans, n);
            ans.deleteCharAt(ans.length() - 1); // backtrack
        }
    }
}