class Solution {
   public:
    int largestRectangleArea(vector<int>& hi) {
        int n = hi.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = 0; i < hi.size(); i++) {
            while (!st.empty() && hi[st.top()] > hi[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && hi[st.top()] > hi[i]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<hi.size();i++){
             int k=hi[i]*(nse[i]-pse[i]-1);
             ans=max(ans,k);
        }
        return ans;
    }
};
