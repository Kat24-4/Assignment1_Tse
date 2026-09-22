#include <algorithm>
#include "include/problem2.hpp"
using namespace std;

template <std::size_t N>
void problem2Count(int (&items)[N]) {
    if (N == 0) {
        return;
    }

    int temp[size];
    std::copy(std::begin(items), std::end(items), temp);

    int count[3] = {0, 0, 0};

    for (int i = 0; i < N; i++) {
        if (items[i] == 0) {
            count[0]++;
        } else if (items[i] == 1) {
            count[1]++;
        } else if (items[i] == 2) {
            count[2]++;
        } else {
            throw "Invalid category - must be 0, 1, or 2 only.";
        }
    }

    for (int j = 1; j <= 2; j++) {
        count[j] = count[j] + count[j - 1];
    }

    for (int k = N - 1; k >= 0; k--) {
        if (temp[k] == 0) {
            items[count[0] - 1] = temp[k];
            count[0]--;
        } else if (temp[k] == 1) {
            items[count[1] - 1] = temp[k];
            count[1]--;
        } else {
            items[count[2] - 1] = temp[k];
            count[2]--;
        }
    }
}

template <std::size_t N>
void problem2Dutch(int (&items)[N]) {
    if (N == 0) {
        return;
    }

    int low = 0;
    int mid = 0;
    int high = N -1;
    int temp;

    while (mid <= high) {
        if (items[mid] == 0) {
            temp = items[low];
            items[low] = items[mid];
            items[mid] = temp;

            low++;
            mid++;
        } else if (items[mid] == 1) {
            mid++;
        } else if (items[mid] == 2) {
            temp = items[high]
            items[high] = items[mid];
            items[mid] = temp;
            
            high--;
        } else {
            throw "Invalid category - must be 0, 1, or 2 only.";
        }
    }
}