/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    public String serialize(TreeNode root) {
        if (root == null) return "";
        StringBuilder s = new StringBuilder();
        LinkedList<TreeNode> queue = new LinkedList<>();

        queue.add(root);
        
        while (!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            
            if (curr == null){
                s.append("#,");
                continue;
            }
            
            s.append(Integer.toString(curr.val) + ',');

            queue.add(curr.left);
            queue.add(curr.right);
        }

        return s.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.length() == 0) return null;

        String[] split = data.split(",");
        int n = split.length;
        int i;


        TreeNode root = new TreeNode(Integer.parseInt(split[0]));
        LinkedList<TreeNode> queue = new LinkedList<>();

        queue.add(root);

        for (i = 1; i < n; i++) {
            TreeNode curr = queue.poll();
            
            if (!split[i].equals("#")) {
                TreeNode left = new TreeNode(Integer.parseInt(split[i]));
                queue.add(left);
                curr.left = left;
            }
            i++;
            
            if (i < n && !split[i].equals("#")) {
                TreeNode right = new TreeNode(Integer.parseInt(split[i]));
                queue.add(right);
                curr.right = right;
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));