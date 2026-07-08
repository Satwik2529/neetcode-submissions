class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=INT_MIN;
        bool found=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) found=true;
            sum=sum+nums[i];
            if(sum<0) sum=0;
            else{
                maxsum=max(sum,maxsum);
            }
        }
        if(!found) return *max_element(nums.begin(),nums.end());
        return maxsum;

    }
};
