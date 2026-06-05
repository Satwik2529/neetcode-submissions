class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans;

        for (int i = 0; i < strs.size(); i++) {
            ans.push_back((char)strs[i].size());
            ans += strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<string> ans;

        int i = 0;

        while (i < s.size()) {
            int len = (unsigned char)s[i];
            i++;

            ans.push_back(s.substr(i, len));

            i += len;
        }

        return ans;
    }
};