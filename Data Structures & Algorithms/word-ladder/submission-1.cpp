class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while (!q.empty()) {
            auto it = q.front();
            string a = it.first;
            int step = it.second;
            if(a==endWord) return step;
            q.pop();
            for (int i = 0; i < a.size(); i++) {
                char store = a[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    a[i] = j;
                    if (st.find(a) != st.end()) {
                        q.push({a, step + 1});
                        st.erase(a);
                    }
                }
                a[i]=store;
            }
        }
        return 0;
    }
};
