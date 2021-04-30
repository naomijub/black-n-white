#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "Tweet.h"
#include "vector"

class RetweetCollection {
    private: 
        std::vector<Tweet> tweets;
    public:
        RetweetCollection() {
        }

        unsigned int size() const {
            return tweets.size();
        }

        bool isEmpty() const {
            return size() == 0;
        }

        void add(const Tweet& tweet) {
            tweets.push_back(tweet);
        }

        void remove(const Tweet& tweet) {
            for(int i = 0; i < tweets.size(); i++) {
                if (tweet.id() == tweets[i].id()) {
                    tweets.erase(tweets.begin() + i);
                }
            }
        }
};

#endif