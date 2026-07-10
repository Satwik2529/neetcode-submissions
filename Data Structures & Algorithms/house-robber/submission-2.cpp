class Solution {
public:
int dfs(int i,vector<int> &dp,vector<int> &nums){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int pick=nums[i]+ dfs(i+2,dp,nums);
    int notpick=dfs(i+1,dp,nums);
    return dp[i]=max(pick,notpick);

}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dfs(0,dp,nums);
        return dp[0];
        
    }
};
