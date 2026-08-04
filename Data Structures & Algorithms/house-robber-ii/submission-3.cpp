class Solution {
   public:
    int solve(int start, int end, vector<int>& nums) {
        
        int nextnext=0;
        int next=0;
        for (int i = end; i >= start; i--) {
            int take = nums[i] + nextnext;
            int ntake = next;
            int current = max(take, ntake);
            nextnext=next;
            next=current;
        }
        return next;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int a = solve(0, n - 2, nums);
        int b = solve(1, n - 1, nums);
        return max(a,b);
    }
};
