class Twitter {
public:
    int time;
    // userID -> all the users this person follows
    unordered_map<int, unordered_set<int>> following;
    // userId -> {time,tweetId} all for this person
    unordered_map<int, vector<pair<int, int>>> posts;
    Twitter() {
        time = 0;
        for (int i = 1; i < 501; i++) {
            following[i].insert(i);
        }
    }

    void postTweet(int userId, int tweetId) {
        time++;
        posts[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto& i : following[userId]) {

            int start = max(0, (int)posts[i].size() - 10);

            for (int j = start; j < posts[i].size(); j++) {

                auto& post = posts[i][j];

                if (pq.size() < 10) {
                    pq.push({post.first, post.second});
                } else if (pq.top().first < post.first) {
                    pq.pop();
                    pq.push({post.first, post.second});
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followeeId == followerId)
            return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId)
            return;
        if (following[followerId].count(followeeId)) {
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */