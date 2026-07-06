class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int start=edges[i][0];
            int end=edges[i][1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        queue<pair<int,int>> q;
        int count=0;
        q.push({0,-1});
        while(!q.empty()){
            auto it =q.front();
            int me=it.first;
            int parent=it.second;
            q.pop();
            count++;
            vis[me]=true;
            for(auto it:adj[me]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it,me});
                }
                else if(vis[it]&&it!=parent){
                    return false;
                }
            }

        }
        return count==n;
        

    }
};
