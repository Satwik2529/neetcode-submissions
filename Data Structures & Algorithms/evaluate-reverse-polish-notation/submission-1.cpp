class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {

            if(tokens[i] != "+" &&
               tokens[i] != "-" &&
               tokens[i] != "*" &&
               tokens[i] != "/") {

                st.push(stoi(tokens[i]));
            }
            else {

                int k = st.top();
                st.pop();

                int r = st.top();
                st.pop();

                int res = 0;

                if(tokens[i][0] == '+') {
                    res = k + r;
                }

                if(tokens[i][0] == '-') {
                    res = r - k;
                }

                if(tokens[i][0] == '*') {
                    res = k * r;
                }

                if(tokens[i][0] == '/') {
                    res = r / k;
                }

                st.push(res);
            }
        }

        return st.top();
    }
};