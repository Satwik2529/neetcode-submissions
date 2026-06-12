class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vt;
        for(int i=0;i<position.size();i++){
            vt.push_back({position[i],speed[i]});
        }
        sort(vt.begin(),vt.end());
        stack<double> st;
        for(int i=0;i<vt.size();i++){
            double time=(double)(target-vt[i].first)/vt[i].second;
            if(st.empty()||st.top()>time){
                st.push(time);
            }
            else{
                while(!st.empty()&&time>=st.top()){
                    st.pop();
                }
                st.push(time);
            }
        }
        return st.size();
        
    }
};
