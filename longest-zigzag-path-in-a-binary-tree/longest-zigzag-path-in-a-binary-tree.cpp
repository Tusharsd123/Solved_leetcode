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
    int max_steps = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root,true,0);
        dfs(root,false,0);
        return max_steps;
    }
    void dfs(TreeNode* root,bool is_left,int steps)
    {
        if(root==NULL)
            return;
        max_steps = max(max_steps,steps);
        if(is_left)
        {
            dfs(root->left,false,steps+1);
            dfs(root->right,true,1);
        }
        else
        {
            dfs(root->right,true,steps+1);
            dfs(root->left,false,1);
        }
    }
};