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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        list<TreeNode*> level;
        level.push_back(root);
        bool rev = false;

        while (level.size() > 0){
            list<TreeNode*> level_temp;
            vector<int> level_ans;

            while(level.size() > 0 && level.front() != NULL){
                if (rev){
                    level_ans.push_back(level.back()->val);

                    if (level.back()->right != NULL) level_temp.push_back(level.back()->right);
                    if (level.back()->left != NULL) level_temp.push_back(level.back()->left);

                    level.pop_back();
                } else {
                    level_ans.push_back(level.front()->val);

                    if (level.front()->left != NULL) level_temp.push_back(level.front()->left);
                    if (level.front()->right != NULL) level_temp.push_back(level.front()->right);
                    
                    level.pop_front();
                }
            }

            level = level_temp;
            if (rev){
                reverse(level.begin(), level.end());
                rev = false;
            } else rev = true;

            if (level_ans.size() > 0) ans.push_back(level_ans);
        }


        return ans;
    }
};