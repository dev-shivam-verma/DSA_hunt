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
    TreeNode first;
    TreeNode middle;
    TreeNode last;

    public void recoverTree(TreeNode root) {
        TreeNode cur = root;
        TreeNode prev = null;

        while (cur != null){
            if (cur.left == null){
                if (prev != null && prev.val > cur.val) {
                    if (first == null) {
                        first = prev;
                        middle = cur;
                    } else last = cur;
                }

                prev = cur;
                cur = cur.right;
            } else {
                TreeNode temp = cur.left;

                while (temp.right != null && temp.right != cur) temp = temp.right;

                if (temp.right == null) {
                    temp.right = cur;
                    cur = cur.left;
                } else {
                    temp.right = null;
                    if (prev != null && prev.val > cur.val) {
                        if (first == null) {
                            first = prev;
                            middle = cur;
                        } else last = cur;
                    }

                    prev = cur;
                    cur = cur.right;
                }
            }
        }

        
        if (last == null) last = middle;

        // swap 
        first.val = first.val + last.val;
        last.val = first.val - last.val;
        first.val = first.val - last.val;
    }
}