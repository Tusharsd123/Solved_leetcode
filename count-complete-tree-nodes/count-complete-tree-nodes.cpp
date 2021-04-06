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
    int right(TreeNode* root)
    {
        int dep=0;
        while(root!=NULL)
        {
            root= root->right;
            dep++;
        }
        return dep;
    }
    int left(TreeNode* root)
    {
        int dep=0;
        while(root!=NULL)
        {
            root = root->left;
            dep++;
        }
        return dep;
    }
    int countNodes(TreeNode* root) {
        int left_depth = left(root);
        int right_depth = right(root);
        if(left_depth==right_depth)
            return (1 << left_depth) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};