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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        int queue_size = 1;
        while(q.size()>0)
        {
            int largest_ele = INT_MIN;
            for(int i = 0;i<queue_size;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                largest_ele = max(largest_ele,curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                     q.push(curr->right);
            }
            
            v.push_back(largest_ele);
            queue_size = q.size();
        }
        return v;
    }
};