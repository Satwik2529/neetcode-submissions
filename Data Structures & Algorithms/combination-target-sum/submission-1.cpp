class Solution {
    vector<vector<int>> ans;
    vector<int> subs;
    int sum=0;
public:
  void dfs(int index,vector<int> &nums,int &t){
    if(index>=nums.size()){
         if(sum==t) ans.push_back(subs);
         return;
    }
    if(sum>t) return;
    sum+=nums[index];
    subs.push_back(nums[index]);
    dfs(index,nums,t);
    subs.pop_back();
    sum-=nums[index];
    dfs(index+1,nums,t);
  }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,nums,target);
        return ans;    
    }
};
