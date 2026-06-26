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
 int dfs(TreeNode * root,int &m){
    if(root==NULL) return 0;
    int l=max(0,dfs(root->left,m));
    int r=max(0,dfs(root->right,m));
    m=max(l+r+root->val,m);
    return root->val+max(l,r);
 }
 
    int maxPathSum(TreeNode* root) {
        int m=INT_MIN;
        int k=dfs(root,m);
        return m;

    }
};
