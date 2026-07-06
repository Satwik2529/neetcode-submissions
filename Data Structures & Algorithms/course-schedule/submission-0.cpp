class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            int ele=prerequisites[i][0];
            int go=prerequisites[i][1];
            adj[ele].push_back(go);
            indegree[go]++;
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        int comp=0;
        while(!q.empty()){
            int hi=q.front();
            q.pop();
            comp++;
            for(auto it:adj[hi]){
                  indegree[it]--;
                  if(indegree[it]==0)q.push(it);
            }
        }
       return numCourses==comp;
        
    }
};
