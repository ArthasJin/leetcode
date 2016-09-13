class Twitter {
private:
    int timestamp;
    unordered_map<int, deque<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followers;
public:
    /** Initialize your data structure here. */
    Twitter() : timestamp(0) {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(timestamp, tweetId));
        timestamp++;
        while (!tweets[userId].empty() && tweets[userId].size() > 10) {
            tweets[userId].pop_front();
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> q(tweets[userId].begin(), tweets[userId].end());
        for (auto followee : followers[userId]) {
            for (auto it = tweets[followee].begin(); it != tweets[followee].end(); ++it) {
                q.push(*it);
            }
        }
        vector<int> res;
        int n = 10;
        while (!q.empty() && n) {
            res.push_back(q.top().second);
            q.pop();
            n--;
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
