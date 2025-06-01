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
    public void flatten(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode temp = root;

        // adding initial null to stack 
        stack.push(null);

        while (temp != null){
            if (temp.left != null){
                TreeNode prev = temp.left;

                while (prev.right != null ) prev = prev.right;
                
                prev.right = temp.right;
                temp.right = temp.left;
                temp.left = null;
            }

            temp = temp.right;
        }
    }
}