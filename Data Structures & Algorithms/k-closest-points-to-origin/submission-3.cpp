class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++){
            int r=points[i][0]*points[i][0]+points[i][1]*points[i][1];
           
            pq.push({r,i});
            while(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            int idx=a.second;
            ans.push_back(points[idx]);
        }
        return ans;

        
    }
};
