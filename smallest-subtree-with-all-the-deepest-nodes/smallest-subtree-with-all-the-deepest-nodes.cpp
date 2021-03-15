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
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(!root || root == p || root == q)
            return root;
        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);
        return !left?right:!right?left:root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root || !root->left && !root->right)
            return root;
        TreeNode *left_most = NULL;
        TreeNode *right_most = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level_size = q.size();
            for(int level = 0;level<level_size;level++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(level==0)
                    left_most = node;
                if(level == level_size-1)
                    right_most = node;
                if(node->left)
                     q.push(node->left);
                if(node->right)
                      q.push(node->right);
            }
        }
        return lca(root,left_most,right_most);
    }
};