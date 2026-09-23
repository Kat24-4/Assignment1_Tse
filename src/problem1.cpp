#include <vector>
#include <algorithm>
#include "../include/problem1.h"
using namespace std;

template <std::size_t N>
std::vector<Interval> problem1(Interval (&intervals)[N]) {
    std::vector<Interval> sorted;
    
    // if array is empty, return empty vector
    if (N == 0) {
        return sorted;
    }

    // utilize built in sort to sort given array (struct has custom sorting)
    std::stable_sort(intervals[0], intervals[N]);

    // add first interval to the final vector 
    sorted.push_back(intervals[0]);

    for (int i = 1; i < N - 1; i++) {
        // check if end of the interval is later than the start of next one
        if (sorted.back().end >= intervals[i].start) {
            // merge intervals by making the later end the new end of the interval
            if (sorted.back().end < intervals[i].end) {
                sorted.back().end = intervals[i].end;
            }
        // else if the interval is not a duplicate, add it to the final list
        } else if (!((sorted.back().start == intervals[i].start) && (sorted.back().end == intervals[i].end))) {
                sorted.push_back(intervals[i]);
        }
    }

    return sorted;

}