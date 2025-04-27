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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        list<TreeNode*> level;
        list<long long unsigned int> level_idx;
        level_idx.push_back(1);
        level.push_back(root);

        while(level.size()> 0){
            int currWidth = (level_idx.back() - level_idx.front()) + 1;
            ans = max(ans, currWidth);
            
            list<TreeNode*> level_temp;
            list<long long unsigned int> level_idx_temp;

            while(level.size() > 0 && level.front() != nullptr){

                if (level.front()->left != nullptr){ 
                    level_temp.push_back(level.front()->left);
                    level_idx_temp.push_back(level_idx.front() * 2);
                }
                if (level.front()->right != nullptr){
                    level_idx_temp.push_back(level_idx.front() * 2 + 1);
                    level_temp.push_back(level.front()->right);
                }
                level_idx.pop_front();
                level.pop_front();
            }            

            level_idx = level_idx_temp;
            level = level_temp;

        }

        return ans;
    }


    
};