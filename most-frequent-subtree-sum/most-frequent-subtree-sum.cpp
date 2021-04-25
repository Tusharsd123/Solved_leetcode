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
    unordered_map<int,int> mp;
    int max_count=0;
    
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int s = dfs(root->left) + dfs(root->right) + root->val;
        max_count = max(max_count,++mp[s]);
        return s;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for(auto i : mp)
        {
            if(i.second==max_count)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};