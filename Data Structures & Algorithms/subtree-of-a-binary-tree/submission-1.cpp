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
    bool issametree(TreeNode * q,TreeNode *r ){
        if(q==NULL&&r==NULL){
            return true;
        }
        if(q==NULL||r==NULL){
            return false;
        }
        if(q->val!=r->val){
            return false;
        }
        return issametree(q->left,r->left)&&issametree(q->right,r->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root==NULL) return false;
         if(issametree(root,subRoot)) return true;
         return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
      
    


    }
};
