class Solution {
   public:
    string ans;
    void topologicalsort(vector<int>& indegree, vector<vector<char>>& adj, vector<bool>& exist) {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && exist[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            char now = 'a' + i;
            ans = ans + now;
            for (auto it : adj[i]) {
                indegree[it - 'a']--;
                if (indegree[it - 'a'] == 0) q.push(it - 'a');
            }
        }
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<char>> adj(26);
        vector<bool> exist(26, false);
        vector<vector<bool>> vis(26, vector<bool>(26, false));
        vector<int> indegree(26, 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                exist[words[i][j] - 'a'] = true;
            }
        }
        for (int i = 1; i < words.size(); i++) {
            if (words[i].size() < words[i - 1].size()) {
                if (words[i - 1].substr(0, words[i].size()) == words[i]) {
                    return "";
                }
            }

            int a = words[i].size();
            int b = words[i - 1].size();
            int k = min(a, b);
            for (int j = 0; j < k; j++) {
                char u = words[i][j];
                char me = words[i - 1][j];
                bool found = false;
                if (me != u) {
                    if (!vis[me - 'a'][u - 'a']) {
                        vis[me - 'a'][u - 'a'] = true;
                        adj[me - 'a'].push_back(u);
                        indegree[u - 'a']++;
                    }
                    break;
                }
            }
        }
        int all = 0;
        topologicalsort(indegree, adj, exist);
        for (int i = 0; i < 26; i++) {
            if (exist[i] == true) all++;
        }
        if (ans.size() == all) return ans;
        return "";
    }
};
