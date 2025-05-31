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
    public List<Integer> preorderTraversal(TreeNode root) {
        TreeNode temp = root;
        List<Integer> result = new ArrayList<>();

        while (temp != null){
            // node processing 
                           

            if (temp.left == null){
                result.add(temp.val); 
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
                    result.add(temp.val); 
                    temp = temp.left;
                } 
                // left subtree is processed
                else {
                    // remove the thread and process current node
                    prev.right = null;
                    temp = temp.right;
                }
            }
        }


        return result;
    }
}