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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        list<TreeNode*> level;
        level.push_back(root);
        while(level.size()> 0){
            list<TreeNode*> level_temp;

            vector<int> level_ans;
            while(level.size() > 0 && level.front() != nullptr){
                level_ans.push_back(level.front()->val);

                if (level.front()->left != nullptr) level_temp.push_back(level.front()->left);
                if (level.front()->right != nullptr) level_temp.push_back(level.front()->right);
                level.pop_front();
            }

            level = level_temp;
            if (level_ans.size() > 0) ans.push_back(level_ans);
        }

        return ans;
    }
};