class Solution {
public:
void dfs(int i,vector<vector<int>> &adj,vector<bool> &vis){
    vis[i]=true;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int start=edges[i][0];
            int end=edges[i][1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;

    }
};
