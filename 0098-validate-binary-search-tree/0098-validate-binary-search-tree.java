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
    public boolean isValidBST(TreeNode root) {
        TreeNode temp = root;
        Integer ans = null;

        while (temp != null){
            if (temp.left == null){
                if (ans != null && ans >= temp.val) return false;

                ans = temp.val;
                temp = temp.right;
                continue;
            } else {
                TreeNode prev = temp.left;

                while (prev.right != null && prev.right != temp) {
                    prev = prev.right;
                }

                // left subtree not processed
                if (prev.right == null) {
                    // establish the thread
                    prev.right = temp;
                    temp = temp.left;
                } 
                // left subtree is processed
                else {
                    // remove the thread and process current node
                    prev.right = null;
                    if (ans != null && ans >= temp.val) return false;

                    ans = temp.val;

                    temp = temp.right;
                }
            }
        }

        return true;
    }
}