#ifndef Chop_h
#define Chop_h

#include <vector>

int chop(int element, std::vector<int> sorted)
{
    for (int i = 0; i < sorted.size(); i++)
    {
        if (element == sorted[i])
            return i;
    }
    return -1;
}

#endif