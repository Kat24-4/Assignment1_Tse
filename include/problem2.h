#include <algorithm>
#include <array>
#ifndef PROBLEM2_H
#define PROBLEM2_H

template <std::size_t N>
void problem2Count(std::array<int, N>& items) {
    // if given array is empty, exit function
    if (N == 0) {
        return;
    }

    // make a copy of the array to use as reference 
    int temp[N];
    std::copy(std::begin(items), std::end(items), temp);

    int count[3] = {0, 0, 0}; // store counts for each category

    // run through the list and count every instance of each category 
    for (int i = 0; i < static_cast<int>(N); i++) {
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

    // updated the count values to represent the last index of each category when sorted 
    for (int j = 1; j <= 2; j++) {
        count[j] = count[j] + count[j - 1];
    }

    // run through the list and move each category to the corresponding section of the vector 
    for (int k = static_cast<int>(N) - 1; k >= 0; k--) {
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
void problem2Dutch(std::array<int, N>& items) {
    // if given array is empty, exit function 
    if (N == 0) {
        return;
    }

    // indexes for low, middle, and high sections of the array 
    int low = 0;
    int mid = 0;
    int high = static_cast<int>(N) - 1;
    int temp;

    while (mid <= high) { // traverse until all items have been seen
        // if the item is 0, swap the low and mid values and continue to the next value
        if (items[mid] == 0) {
            temp = items[low];
            items[low] = items[mid];
            items[mid] = temp;

            low++;
            mid++;
        // if item is 1, it is already in the middle so just move to the next 
        } else if (items[mid] == 1) {
            mid++;
        // if item is 2, swap high and mid and only increment high because you need to re-check mid
        } else if (items[mid] == 2) {
            temp = items[high];
            items[high] = items[mid];
            items[mid] = temp;
            
            high--;
        } else {
            throw "Invalid category - must be 0, 1, or 2 only.";
        }
    }
}

void problem2Count(int items[], int N);

void problem2Dutch(int items[], int N);

#endif