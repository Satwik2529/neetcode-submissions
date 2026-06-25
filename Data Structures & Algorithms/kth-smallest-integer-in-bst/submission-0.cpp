class Solution {
   public:
    TreeNode* ans = NULL;

    void dfs(TreeNode* root, int& k) {
        if (root == NULL) return;

        dfs(root->left, k);

        k--;

        if (k == 0) ans = root;

        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans->val;
    }
};