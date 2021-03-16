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
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root,int d)
    {
        vector<int> p = {};
        if(root==NULL)
            return p;
        auto left = dfs(root->left,d);
        auto right = dfs(root->right,d);
        if(left.size()==0 && right.size()==0)
        {
            p.push_back(1);
            return p;
        }
        for(int i = 0;i<left.size();i++)
        {
            for(int j = 0;j<right.size();j++)
            {
                if(left[i]+right[j]<=d)
                    ans++;
            }
        }
        
        for(int i = 0;i<left.size();i++)
        {
            left[i]++;
            p.push_back(left[i]);
        }
        
        for(int j = 0;j<right.size();j++)
        {
            right[j]++;
            p.push_back(right[j]);
        }
        return p;
    }
};