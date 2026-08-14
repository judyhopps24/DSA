class Twitter {
public:

    unordered_map<int,vector<pair<int,int>>> userToTweetIds; //user -> set[(count, tweetID)];
    unordered_map<int,set<int>> userToFollowing; //user -> followinga
    
    int count;

    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        userToTweetIds[userId].push_back({count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        set<int> feedSources =  userToFollowing[userId];
        feedSources.insert(userId);

        for(auto source: feedSources){
            if(!userToTweetIds[source].empty()){
                vector<int> temp;


                int size = userToTweetIds[source].size();
                pair<int,int> tw = userToTweetIds[source][size-1];
                temp.push_back(tw.first); //count
                temp.push_back(tw.second); //tweetID
                temp.push_back(source); //followingId
                temp.push_back(size-1); //index of tweet

                pq.push(temp);
            }
        }

        vector<int> res;

        while( !pq.empty() && res.size()<10){
            vector<int> top = pq.top();
            pq.pop();

            res.push_back(top[1]);

            //if the nextIndex of that follower is greater than 0 and it is within the size
            if(top[3] -1 >=0 && userToTweetIds[top[2]].size()>= top[3] -1){
                pair<int,int> tw = userToTweetIds[top[2]][top[3] -1];
                vector<int> temp;
                temp.push_back(tw.first); //count
                temp.push_back(tw.second); //tweetID
                temp.push_back(top[2]); //followingId
                temp.push_back(top[3] -1); //index of tweet

                pq.push(temp);
            }

        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        userToFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userToFollowing[followerId].erase(followeeId);
    }
};
