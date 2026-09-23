#ifndef INTERVALS_H
#define INTERVALS_H

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

#endif