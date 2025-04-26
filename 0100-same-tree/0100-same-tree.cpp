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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // base case
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        bool isLeftIden = isSameTree(p->left, q->left);
        bool isRightIden = isSameTree(p->right, q->right);

        return isLeftIden && isRightIden && p->val == q->val;            
    }
};