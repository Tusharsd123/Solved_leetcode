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
    set<int> s;
    void util(TreeNode* &root)
    {
        if(root!=NULL)
        {
            util(root->left);     //post order traversal
            util(root->right);
            if(s.find(root->val)!=s.end())
            {
                if(root->left)
                     v.push_back(root->left);
                if(root->right)
                      v.push_back(root->right);
                root = NULL;
                delete root;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i = 0;i<to_delete.size();i++)
               s.insert(to_delete[i]);
        util(root);
        if(root)
            v.push_back(root);
        return v;
    }
};