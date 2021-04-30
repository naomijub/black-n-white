#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "Tweet.h"

class RetweetCollection {
    private: 
        unsigned int size_;
    public:
        RetweetCollection()
            : size_(0){
        }

        unsigned int size() const {
            return size_;
        }

        bool isEmpty() const {
            return size() == 0;
        }

        void add(const Tweet& tweet) {
            size_ = 1;
        }

        void remove(const Tweet& tweet) {
            size_ = 0;
        }
};

#endif