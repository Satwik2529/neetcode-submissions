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
 TreeNode * construct(vector<int> &inorder,int instart,int inend,vector<int> &preorder,int prestart,int preend,map<int,int> &idx){
          if(instart>inend||prestart>preend) return NULL;
          TreeNode * root=new TreeNode(preorder[prestart]);
          int index=idx[preorder[prestart]];
          int numsleft=index-instart;
          root->left=construct(inorder,instart,index-1,preorder,prestart+1,prestart+index,idx);
          root->right=construct(inorder,index+1,inend,preorder,prestart+numsleft+1,preend,idx);
         return root;
  

 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> idx;
        for(int i=0;i<inorder.size();i++){
            idx[inorder[i]]=i;
        }
        TreeNode* root=construct(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,idx);
        return root;
        
    }
};
