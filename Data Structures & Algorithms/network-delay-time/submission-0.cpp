class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int start = times[i][0];
            int end = times[i][1];
            int time = times[i][2];
            adj[start].push_back({end, time});
        }
        vector<int> vis(n + 1, INT_MAX);
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vis[k] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int ele = it.second;
            if (time > vis[ele]) continue;
            for (auto it : adj[ele]) {
                int toit = it.second;
                int nei = it.first;
                int tot = toit + time;
                if (tot < vis[nei]) {
                    pq.push({tot, nei});
                    vis[nei] = tot;
                }
            }
        }
    
        for(int i=1;i<=n;i++){
            if(vis[i]==INT_MAX){
                return -1;
            }
        }
        return *max_element(vis.begin()+1,vis.end());
    }
};
