#ifndef Tweet_h
#define Tweet_h

#include "Tweet.h"
#include "string"

class Tweet {
    public:
        Tweet(std::string msg, std::string user) {
            msg_ = msg;
            user_ = user;
        }

        std::string id() const {
            return msg_ + "+" + user_;
        }

    private:
        std::string msg_;
        std::string user_;
};

#endif