class Twitter {
    vector<pair<int,int>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:


    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        pair<int,int> tweet(tweetId, userId);
        tweets.push_back(tweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = tweets.size();
        vector<int> feed;
        for (int i = n -1; i >= 0; i--){
            int tweetId = tweets[i].first;
            int author = tweets[i].second;
            bool hasFollowedSomeone = following.find(userId) != following.end();

            if (author == userId || hasFollowedSomeone && following[userId].find(author) != following[userId].end()){
                feed.push_back(tweetId);
            }
            if (feed.size() >= 10) return feed;
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (following.find(followerId) != following.end()){
            following[followerId].insert(followeeId);
        } else {
            unordered_set<int> followings;
            followings.insert(followeeId);

            following[followerId] = followings;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId) != following.end()){
            if (following[followerId].find(followeeId) != following[followerId].end()){
                following[followerId].erase(followeeId);
            }
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