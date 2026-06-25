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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> hi;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            vector<int> ans;
            for(int i=0;i<k;i++){
                TreeNode * copy=q.front();
                q.pop();
                ans.push_back(copy->val);
                if(copy->left) q.push(copy->left);
                if(copy->right)q.push(copy->right);
            }
            hi.push_back(ans);
        }
        return hi;

        
    }
};
