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
    vector<TreeNode*> v;
    string inorder(TreeNode* root,unordered_map<string,int> &mp)
    {
        if(root==NULL)
            return "";
        string str = "(";
        str += inorder(root->left,mp);
        str += to_string(root->val);
        str += inorder(root->right,mp);
        str += ")";
        
        if(mp[str]==1)
            v.push_back(root);
        mp[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       unordered_map<string,int> mp;
        inorder(root,mp);
        return v;
    }
};