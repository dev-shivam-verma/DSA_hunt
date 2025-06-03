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
    public int kthSmallest(TreeNode root, int k) {
        TreeNode temp = root;
        int ans = 0;
        int remaining = k;

        while (temp != null){
            if (remaining == 0) return ans;

            if (temp.left == null){
                ans = temp.val;
                remaining--;
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
                    ans = temp.val;
                    remaining--;

                    temp = temp.right;
                }
            }
        }

        return ans;
    }
}