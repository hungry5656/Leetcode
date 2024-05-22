class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        twitterFeeds.push_back({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> retVec;
        unordered_set<int> followList = userFollowList[userId];
        int idx = twitterFeeds.size() - 1;
        while (retVec.size() < 10 && idx >= 0) {
            if (twitterFeeds[idx].second == userId || followList.find(twitterFeeds[idx].second) != followList.end()) {
                retVec.push_back(twitterFeeds[idx].first);
            }
            idx--;
        }
        return retVec;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowList[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowList[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> userFollowList;
    vector<pair<int, int>> twitterFeeds;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */