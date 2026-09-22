#include <vector>
#ifndef PROBLEM7_H
#define PROBLEM7_H

struct CountPair {
    int value;
    int count;

    bool operator<(const CountPair& other) const {
        return count < other.count;
    }
};

template <std::size_t N>
std::vector<int> problem7(int (&nums)[N], int k);

#endif