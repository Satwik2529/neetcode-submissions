class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count0 = 0;
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count0++;
                continue;
            }
            product = product * nums[i];
        }
        vector<int> ans(nums.size(), 0);
        if (count0 >= 2) {
            return ans;
        } else if (count0 == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    ans[i] = product;
                }
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
};
