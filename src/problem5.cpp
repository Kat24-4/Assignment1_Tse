#include <vector>
#include <algorithm>
#include "../include/problem5.h"
using namespace std;


bool problem5(Interval intervals[], int N) {
    // if list is empty, then return true (can attend all meetings)
    if (N == 0) {
        return true;
    }

    // sort intervals by start time (struct has custom sort)
    std::stable_sort(intervals, intervals + N);

    // check if any intervals overlap and if so, return false (cannot attend all meetings)
    for (int i = 0; i < static_cast<int>(N) - 1; i++) {
        if (intervals[i].end > intervals[i + 1].start) {
            return false;
        } else if ((intervals[i].start == intervals[i + 1].start) && (intervals[i].end == intervals[i + 1].end)) {
            return false;
        }
    }

    return true;
}
