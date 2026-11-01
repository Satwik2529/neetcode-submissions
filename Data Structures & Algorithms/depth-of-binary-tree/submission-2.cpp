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
        queue<TreeNode*> pq;
        pq.push(root);
        int count=0;
        while(!pq.empty()){
            int k=pq.size();
            for(int i=0;i<k;i++){
                TreeNode * temp=pq.front();
                pq.pop();
                if(temp->left) pq.push(temp->left);
                if(temp->right)pq.push(temp->right);
            }
            count++;
        }
        return count;
        
    }
};
