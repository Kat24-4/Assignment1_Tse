#include <vector>
#include <algorithm>
#include "../include/problem1.hpp"
using namespace std;

template <std::size_t N>
std::vector<Interval> problem1(Interval (&intervals)[N]) {
    std::vector<Interval> sorted;
    
    if (N == 0) {
        return sorted;
    }

    std::stable_sort(intervals[0], intervals[N]);

    sorted.push_back(intervals[0]);

    for (int i = 1; i < N - 1; i++) {
        if (sorted.back().end >= intervals[i].start) {
            if (sorted.back().end < intervals[i].end) {
                sorted.back().end = intervals[i].end;
            } else if (!((sorted.back().start == intervals[i].start) && (sorted.back().end == intervals[i].end))) {
                sorted.push_back(intervals[i]);
            }
        }
    }

    return sorted;

}