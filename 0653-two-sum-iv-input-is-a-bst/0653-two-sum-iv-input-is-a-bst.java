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
    public boolean findTarget(TreeNode root, int k) {
        TreeNode cur = root; 
        List<Integer> list = new ArrayList<>();

        while (cur != null){
            if (cur.left == null){
                list.add(cur.val);
                cur = cur.right;
            } else {
                TreeNode prev = cur.left;

                while (prev.right != null && prev.right != cur ) {
                    prev = prev.right;
                }

                if (prev.right == null){
                    prev.right = cur;
                    cur = cur.left;
                } else {
                    prev.right = null;
                    list.add(cur.val);

                    cur = cur.right;
                }
            }
        }


        int n = list.size();
        int i = 0; 
        int j = n - 1; 

        while (i < j){
            if (list.get(i) + list.get(j) > k) j--;
            else if (list.get(i) + list.get(j) < k) i++;
            else return true; 
        }
        

        return false;
    }
}