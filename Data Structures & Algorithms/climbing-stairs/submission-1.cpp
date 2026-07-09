class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int cur = 2;
        int prev = 1;
        int ans = 0;
        for (int i = 3; i <= n; i++) {
            ans = cur + prev;

            prev = cur;
            cur = ans;
        }
        return ans;
    }
};
