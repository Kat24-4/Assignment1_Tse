#include <vector>
#ifndef PROBLEM1_H
#define PROBLEM1_H

// custom struct for intervals that have a start and end value 
struct Interval {
    int start;
    int end;

    bool operator<(const Interval& other) const {
        return start < other.start;
    }

    bool operator==(const Interval& other) const {
        return (start == other.start && end == other.end);
    }
};

template <std::size_t N>
std::vector<Interval> problem1(Interval (&intervals)[N]);

#endif