#include <vector>
#include <algorithm>
#include "../include/problem5.hpp"
using namespace std;

template <std::size_t N>
bool problem5(Interval (&intervals)[N]) {
    if (N == 0) {
        return true;
    }

    std::stable_sort(intervals[0], intervals[N]);

    for (int i = 0; i < N - 1; i++) {
        if (intervals[i].end > intervals[i + 1].start) {
            return false;
        } else if ((intervals[i].start == intervals[i + 1].start) && (intervals[i].end == intervals[i + 1].end)) {
            return false;
        }
    }

    return true;
}