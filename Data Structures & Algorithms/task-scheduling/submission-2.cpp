class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        map<char, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto it : mp) {
            if (it.second > 0) pq.push(it.second);
        }
        while (!pq.empty()) {
            vector<int> hi;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int k = pq.top();
                    pq.pop();
                    k--;
                    hi.push_back(k);
                }
            }
            for (int i = 0; i < hi.size(); i++) {
                if (hi[i] > 0) pq.push(hi[i]);
            }
            if (pq.empty()) {
                time = time + hi.size();
            } else {
                time = time + n + 1;
            }
        }
        return time;
    }
};
