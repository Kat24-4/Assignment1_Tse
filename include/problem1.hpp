#include <vector>
#ifndef PROBLEM1_H
#define PROBLEM1_H

struct Interval {
    int start;
    int end;

    bool operator<(const Interval& other) const {
        return start < other.start;
    }
};

std::vector<Interval> problem1(Interval intervals[], int size);

#endif