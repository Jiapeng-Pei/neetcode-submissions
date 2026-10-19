/*
首先先确定这道题需要的数据结构
1. 需要一个数据结构保存users和它们的关注。一个map是可以的  map<int, set<int>> 
2. 需要一个数据结构保存user和它们的post id，post time。可以用另一个map来保存。I can use an integer for postTime.
    - 而且我永远只需要保存top 10最新的post就够了。而且时间只会递增 可以用一个queue来保存
3. 如何尽快地获取newsFeed呢？维护一个size为10的priority queue，遍历其所有following的post，时间复杂度为 nlong10，其中n是所有发的post的数量
*/

#include <bits/stdc++.h>

using namespace std;

class Twitter {
private:
    unordered_map<int, unordered_set<int>> userFollowing;
    unordered_map<int, deque<pair<int,int>>> userTweets; // first is time, second is tweetId
    int time; 

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        deque<pair<int,int>>& tweets = userTweets[userId];
        tweets.push_front({time++, tweetId});
        if (tweets.size() > 10) tweets.pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        // I need 10 most recent (ones with biggest time), so I should keep a small heap. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int followingId : userFollowing[userId]) {
            deque<pair<int, int>>& tweets = userTweets[followingId];
            for (auto& tweet : tweets) {
                pq.push(tweet);
                if (pq.size() > 10) pq.pop();
            }
        }
        deque<pair<int, int>>& tweets = userTweets[userId];
        for (auto& tweet : tweets) {
            pq.push(tweet);
            if (pq.size() > 10) pq.pop();
        }

        // I need to reverse the ret here, since the first is the one with earliest time
        vector<int> ret;
        while (pq.size()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
    }
};
