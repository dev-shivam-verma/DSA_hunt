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
    public TreeNode bstFromPreorder(int[] preorder) {
        int n = preorder.length;
        if (n == 0) return null;

        TreeNode root = new TreeNode(preorder[0]);
        Stack<TreeNode> stk = new Stack<>();

        stk.push(root);

        for (int i = 1; i < n; i++){
            TreeNode cur = new TreeNode(preorder[i]);

            if (stk.peek().val > cur.val){
                stk.peek().left = cur;
            } else {
                TreeNode prev = stk.pop();

                while (!stk.isEmpty() && stk.peek().val < cur.val){
                    prev = stk.pop();
                }

                prev.right = cur;
            }

            stk.push(cur);
        }

        return root;
    }
}