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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct_tree(nums,0,nums.size()-1);
    }
    
    TreeNode* construct_tree(vector<int> &nums,int start,int end)
    {
        if(start > end)
             return nullptr;
        int index = -1;
        int val = -1;
        for(int i = start;i<=end;i++)
        {
            if(nums[i]>val)
            {
                val = nums[i];
                index = i;
            }
        }
        
        TreeNode* root = new TreeNode(val);
        root->left = construct_tree(nums,start,index-1);
        root->right = construct_tree(nums,index+1,end);
        return root;
    }
};