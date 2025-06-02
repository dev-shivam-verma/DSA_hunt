/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);

        TreeNode par = root;
        TreeNode ptr = root;

        while (ptr != null){
            par = ptr;

            if (ptr.val > val){
                ptr = ptr.left;
            } else {
                ptr = ptr.right;
            }
        }

        TreeNode child = new TreeNode(val);

        if (val < par.val) par.left = child;
        else par.right = child;

        return root;
    }
}