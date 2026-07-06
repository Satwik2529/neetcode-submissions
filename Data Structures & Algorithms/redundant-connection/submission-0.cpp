class Solution {
   public:
    class disjointset {
        vector<int> rank, parent;

       public:
        disjointset(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);

            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        int up(int u) {
            if (parent[u] == u) return u;
            return parent[u] = up(parent[u]);
        }
        void unionbyrank(int u, int v) {
            int upu = up(u);
            int upv = up(v);
            if (upu == upv) return;
            if (rank[upu] > rank[upv]) {
                parent[upv] = upu;
            } else if (rank[upv] > rank[upu]) {
                parent[upu] = upv;
            } else {
                parent[upu] = upv;
                rank[upv]++;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int k = edges.size();
        disjointset ds(k);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (ds.up(a) == ds.up(b))
                return {a, b};
            else {
                ds.unionbyrank(a,b);
            }
        }
        return {};
    }
};
