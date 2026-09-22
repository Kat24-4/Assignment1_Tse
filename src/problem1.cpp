#include <iostream>
#include <vector>
#include <algorithm>
#include <include/problem1.hpp>
using namespace std;

std::vector<Interval> problem1(Interval intervals[], int size) {
    std::vector<Interval> sorted;
    
    if (size == 0) {
        return sorted;
    }

    int n = sizeof(intervals) / sizeof(intervals[0]);
    std::stable_sort(intervals, intervals + n);

    sorted.push_back(intervals[0]);

    for(int i = 1; i < size - 1; i++) {
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