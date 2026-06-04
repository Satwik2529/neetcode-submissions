class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m1;
        for(int i=0;i<strs.size();i++){
            vector<int> fre(26,0);
            for(int j=0;j<strs[i].size();j++){
                fre[strs[i][j]-'a']++;
            }
            string key=to_string(fre[0]);
            for(int i=1;i<26;i++){
                key=key+','+to_string(fre[i]);
            }
            m1[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:m1){
            ans.push_back(it.second);
        }
        return ans;
    }
};
