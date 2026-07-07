class Solution {
   public:
    map<string, multiset<string>> hi;
    vector<string> ans;
    void dfs(string start) {
        while (!hi[start].empty()) {
              auto it=hi[start].begin();
              string copy=*it;
              hi[start].erase(it);
              dfs(copy);
        }
        ans.push_back(start);
        return;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto it : tickets) {
            hi[it[0]].insert(it[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
