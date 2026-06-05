class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       int maxse=0;
        for(int i=0;i<nums.size();i++){
        int len=0;
             if(mp.find(nums[i]-1)==mp.end()){
                while(mp.find(nums[i])!=mp.end()){
                    len++;
                    nums[i]++;
                }
                maxse=max(maxse,len);
             }
        }
        return maxse;
    }
};
