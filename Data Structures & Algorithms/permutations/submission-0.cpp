class Solution {
   public:
    void dfs(vector<vector<int>>& ans, vector<int> &ds, vector<bool> che, int k, vector<int>& nums) {
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!che[i]) {
                ds.push_back(nums[i]);
                che[i] = true;
                dfs(ans, ds, che, k, nums);
                che[i] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int k = nums.size();
        vector<bool> che(k, false);
        dfs(ans, ds, che, k, nums);
        return ans;
    }
};
