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
    map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(root==NULL)
              return 0;
        if(dp.find(root)!=dp.end())
            return dp[root];
        int total = 0;
        if(root->left!=NULL)
            total += rob(root->left->left) + rob(root->left->right);
        if(root->right!=NULL)
            total += rob(root->right->left) + rob(root->right->right);
        return dp[root] = max(root->val+total,rob(root->left)+rob(root->right));
    }
};