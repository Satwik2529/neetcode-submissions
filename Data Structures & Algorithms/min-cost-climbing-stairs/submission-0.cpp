class Solution {
   public:
    int go(int i, vector<int>& cost,vector<int> &dp) {
        if (i >= cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i] + min(go(i + 1, cost,dp), go(i + 2, cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        vector<int> dp(n,-1);
        int k = min(go(0, cost,dp), go(1, cost,dp));
        return k;
    }
};
