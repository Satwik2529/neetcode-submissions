class Solution {
   public:
    void generate(int index, vector<int>& nums, set<vector<int>>& ans, int& s, vector<int> temp) {
        if (index == s ) {
            ans.insert(temp);
            return ;
        }
        temp.push_back(nums[index]);
        generate(index + 1, nums, ans,s,temp);
        temp.pop_back();
        generate(index + 1, nums, ans,s,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;
        int s = nums.size();
        generate(0, nums, ans, s, temp);
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};
