class Solution {
   public:
    TreeNode* prev = NULL;

    void dfs(TreeNode* root,bool &found) {
        if (root == NULL) return ;
        dfs(root->left,found);
        if (prev && prev->val >= root->val) found=false;
        prev = root;
         dfs(root->right,found);
    }

    bool isValidBST(TreeNode* root) {
        bool found = true;
         dfs(root, found);
         return found;
    }
};