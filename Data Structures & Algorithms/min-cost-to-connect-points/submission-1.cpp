class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        int minwei = 0;
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int wei = it.first;
            int node = it.second;
            if (vis[node]) continue;
            vis[node] = true;
            minwei = minwei + wei;
            for (int i = 0; i < points.size(); i++) {
                if (!vis[i]) {
                    int dist =
                        abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    q.push({dist, i});
                }
            }
        }
        return minwei;
    }
};
