/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int s = p.val;
        int l = q.val;

        if (l < s) {
            // swap
            s = s + l;
            l = s - l;
            s = s - l;
        }

        TreeNode temp = root;
        TreeNode anc = root;

        while (true){
            anc = temp;

            if (temp.val < s){
                temp = temp.right;
            } else if (temp.val > l){
                temp = temp.left;
            } else {
                break;
            }
        }

        return anc;        
    }
}