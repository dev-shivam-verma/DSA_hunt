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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;

        // finding location of the node
        TreeNode cur = root;
        TreeNode par = null;

        while (cur != null && cur.val != key) {
            par = cur;
            if (cur.val > key) cur = cur.left;
            else cur = cur.right;
        }

        if (par == null){ 
            par = new TreeNode(999999);
            par.left = cur;    
        }

        if (cur != null) {
            if (cur.left != null && cur.right != null) caseB(cur, par);
            else caseA(cur,par);
        }

        if (root.val == key) return par.left;


        return root;
    }


    // when cur have two childs 
    public void caseB (TreeNode cur, TreeNode par) {
        // finding inorder successor
        TreeNode suc = cur.right;
        TreeNode sucPar = cur;
        while (suc.left != null){
            sucPar = suc;
            suc = suc.left;
        }

        caseA(suc, sucPar);

        if (par.left == cur) par.left = suc;
        else par.right = suc;


        suc.left = cur.left;
        suc.right = cur.right;
    }    

    // when cur have one or zero childs
    public void caseA (TreeNode cur, TreeNode par){
        TreeNode child = null;
        if (cur.left == null) child = cur.right;
        else child = cur.left;

        if (par.left == cur) par.left = child;
        else par.right = child;
    }
}