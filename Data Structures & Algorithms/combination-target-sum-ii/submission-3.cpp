class Solution {
   public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int> temp, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i - 1] == candidates[i]) continue;
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            dfs(i + 1, temp, candidates, target-candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(0, temp, candidates, target);
        return ans;
    }
};
