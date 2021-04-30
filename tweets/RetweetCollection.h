#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "Tweet.h"
#include "vector"

class RetweetCollection {
    private: 
        std::vector<Tweet> tweets;

        const bool contains(const Tweet& tweet) {
            bool contains_ = false;
            for(Tweet t : tweets) {
                if (tweet.id() == t.id()) {
                    contains_ = true;
                }
            }

            return contains_;

            // OR
            // #include <algorithm>
            // if (std::find(tweets.begin(), tweets.end(), tweet) != tweets.end()) {
            //     return true;
            // } else {
            //     return false;
            // }
        }
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
            if (!contains(tweet)) {
                tweets.push_back(tweet);
            }
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