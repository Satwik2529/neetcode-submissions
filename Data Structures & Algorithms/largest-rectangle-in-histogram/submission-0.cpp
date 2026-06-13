class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        heights.push_back(0);
        int n=heights.size();
        stack<int> st;
        int hi=INT_MIN;
        for(int i=0;i<n;i++){
             while(!st.empty()&&heights[st.top()]>=heights[i]){
                int element=heights[st.top()];
                st.pop();
                int pse=st.empty()?-1:st.top();
                hi=max(hi,element*(i-pse-1));
             }
             st.push(i);
        }
      
        return hi;
    }
};