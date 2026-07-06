class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<prerequisites.size();i++){
            int ele=prerequisites[i][0];
            int go=prerequisites[i][1];
            adj[go].push_back(ele);
            indegree[ele]++;
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int hi=q.front();
            q.pop();
            ans.push_back(hi);
            for(auto it:adj[hi]){
                  indegree[it]--;
                  if(indegree[it]==0)q.push(it);
            }
        }
        if(ans.size()!=numCourses) return {};
       return ans;
    }
};
