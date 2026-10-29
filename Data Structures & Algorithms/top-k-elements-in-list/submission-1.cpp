class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v1;
        map<int,int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto &it : mp) {
            v1.push_back({it.second, it.first});
        }

        sort(v1.begin(), v1.end(), greater<pair<int,int>>());

        for(int i = 0; i < k; i++) {
            ans.push_back(v1[i].second);
        }

        return ans;
    }
};