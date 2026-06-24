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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        int count=0;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                TreeNode*a=q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            count++;
        }
        return count;
        
    }
};
