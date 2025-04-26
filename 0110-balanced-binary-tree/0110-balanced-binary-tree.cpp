/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return f(root);
    }

    bool f(TreeNode* node){
        if (node == nullptr) return true;

        bool left = f(node->left);
        bool right = f(node->right);

        int hLeft = findHeight(node->left);
        int hRight = findHeight(node->right);
        int bf = abs(hLeft - hRight);

        return left && right && bf < 2;
    }

    int findHeight(TreeNode* node){
        if (node == nullptr) return 0;


        int left = findHeight(node->left);
        int right = findHeight(node->right);

        return max(left, right) + 1;
    }
};