class Twitter {
   public:
    int time;
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, set<int>> fo;
    Twitter() {
        time=0;
    }

    void postTweet(int userId, int tweetId) {
        time++;
        posts[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        if (!posts[userId].empty()) {
            int idx = posts[userId].size() - 1;
            pq.push({posts[userId][idx].first, posts[userId][idx].second, userId, idx});
        }
        for (auto it : fo[userId]) {
            if (!posts[it].empty()) {
                int idx = posts[it].size() - 1;
                pq.push({posts[it][idx].first, posts[it][idx].second, it, idx});
            }
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            auto cur = pq.top();
            pq.pop();
            int tweet = cur[1];
            int user = cur[2];
            int index = cur[3];
            index--;
            ans.push_back(tweet);
            if (index >= 0) {
                pq.push({posts[user][index].first, posts[user][index].second, user, index});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) { 
        if(followerId==followeeId) return;
        fo[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { 
        if(followerId==followeeId) return;
        fo[followerId].erase(followeeId); }
};
