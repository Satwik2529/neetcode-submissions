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
 int dfs(TreeNode* root,int &diff){
       if(diff>=2) return 2;
       if(root==0) return 0;
      int lh=dfs(root->left,diff);
      int  rh=dfs(root->right,diff);
       diff=max(diff,abs(lh-rh));
       return 1+max(lh,rh) ;

  }
    bool isBalanced(TreeNode* root) {
        int diff=0;
        dfs(root,diff);
        return diff<2;
        
        
    }
};
