class Solution {
   public:
    vector<vector<int>> ans;
    void dfs(int index,int sum,vector<int> temp,int &target,vector<int> &nums){
        if(sum>target){
            return;
        }
        if(index>=nums.size()){
            if(sum==target) ans.push_back(temp);
            return ;
        }
        sum=sum+nums[index];
        temp.push_back(nums[index]);
        dfs(index,sum,temp,target,nums);
        sum=sum-nums[index];
        temp.pop_back();
        dfs(index+1,sum,temp,target,nums);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        int sum=0;
        dfs(0,sum,temp,target,nums);
        return ans;
    }
};
