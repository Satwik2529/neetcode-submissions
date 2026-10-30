class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();

        heights.push_back(0);

        for(int i = 0; i <= n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {

                int hei = heights[st.top()];
                st.pop();

                int pse = st.empty() ? -1 : st.top();

                int len = i - pse - 1;

                ans = max(ans, hei * len);
            }

            st.push(i);
        }

        return ans;
    }
};