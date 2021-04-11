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
    int sum = 0;
    
    int solve(TreeNode* root,int left,int right)
    {
        if(root)
        {
            solve(root->left,left,right);
            if(root->val>=left && root->val<=right)
                sum += root->val;
            solve(root->right,left,right);
        }
        
        return sum;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        return solve(root,low,high);
    }
};