class Solution {
   public:
    int solve(int index, int end, vector<int>& nums, vector<int>& dp) {
        if (index > end) return 0;

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(index + 2, end, nums, dp);
        int notPick = solve(index + 1, end, nums, dp);

        return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int a = solve(0, n - 2, nums, dp1);
        int b = solve(1, n - 1, nums, dp2);

        return max(a, b);
    }
};