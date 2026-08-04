class Solution {
   public:
    int solve(int start, int end, vector<int>& nums) {
        vector<int> dp(nums.size() + 2, 0);
        for (int i = end; i >= start; i--) {
            int take = nums[i] + dp[i + 2];
            int ntake = dp[i + 1];
            dp[i] = max(take, ntake);
        }
        return dp[start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int a = solve(0, n - 2, nums);
        int b = solve(1, n - 1, nums);
        return max(a,b);
    }
};
