class Solution {
   public:
    vector<vector<string>> ans;

    bool isp(string& s, int start, int end) {
        if(start==end) return true;
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void dfs(int index, string& s, vector<string>& path) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isp(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(0, s, path);
        return ans;
    }
};
