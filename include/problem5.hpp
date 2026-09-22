#include <vector>
#ifndef PROBLEM5_H
#define PROBLEM5_H

struct Interval {
    int start;
    int end;

    bool operator<(const Interval& other) const {
        return start < other.start;
    }
};

template <std::size_t N>
bool problem5(Interval (&intervals)[N]);

#endif