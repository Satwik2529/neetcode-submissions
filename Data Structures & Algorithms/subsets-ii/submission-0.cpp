
class Solution {
   public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int> temp, vector<int>& candidates) {
       
            ans.push_back(temp);
         
        
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i - 1] == candidates[i]) continue;
            temp.push_back(candidates[i]);
            dfs(i + 1, temp, candidates);
            temp.pop_back();
        }
    }
     vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(0, temp, candidates);
        return ans;
    }
};
