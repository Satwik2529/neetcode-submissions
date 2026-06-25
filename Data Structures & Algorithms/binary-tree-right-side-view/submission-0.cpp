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

    vector<int> rightSideView(TreeNode* root) {
       if(root==NULL) return {};
       vector<int> ans;
       queue<TreeNode*> q;
       q.push(root);
     
       while(!q.empty()){
           int k=q.size();
           for(int i=0;i<k;i++){
            TreeNode* copy=q.front();
            q.pop();
            if(copy->left) q.push(copy->left);
            if(copy->right) q.push(copy->right);
            if(i==k-1){
                ans.push_back(copy->val);
            }
           }
       }
     return ans;
        
    }
};
