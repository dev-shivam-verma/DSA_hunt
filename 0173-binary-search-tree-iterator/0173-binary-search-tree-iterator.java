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
class BSTIterator {
    TreeNode it ;
    Stack<TreeNode> stk ;

    public BSTIterator(TreeNode root) {
        it = new TreeNode(0);
        stk = new Stack<>();

        fillStack(stk, root);
    }
    
    public int next() {
        if (it.right != null) {
            fillStack(stk, it.right);
        }

        it = stk.pop();
        return it.val;
    }
    
    public boolean hasNext() {
        return it.right != null || !stk.isEmpty();
    }

    public void fillStack(Stack<TreeNode> stk, TreeNode root){
        TreeNode cur = root;

        while (cur != null){
            stk.push(cur);
            cur = cur.left;
        }
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */