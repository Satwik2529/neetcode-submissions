class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];
            adj[start].push_back({end, cost});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto [steps, ele] = q.top();
            auto [node, d] = ele;
            q.pop();
            if (steps > k) continue;
            for (auto it : adj[node]) {
                int nei = it.first;
                int mydis = it.second;
                if (d + mydis < dist[nei]) {
                    dist[nei] = d + mydis;
                    q.push({steps + 1, {nei, d + mydis}});
                }
            }
        }
        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
