class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res={{}};
        for(int i=0;i<nums.size();i++){
            int k=res.size();
            for(int j=0;j<k;j++){
                vector<int> subset;
                subset=res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        return res;
        
    }
};
