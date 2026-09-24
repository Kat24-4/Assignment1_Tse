#include <vector>
#include <array>
#ifndef PROBLEM10_H
#define PROBLEM10_H

// modified merge sort to count inversions
template <std::size_t N>
static int merge(std::array<int, N>& vals, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> ltemp, rtemp;

    for (int l = 0; l < n1; l++) {
        ltemp.push_back(vals[left + l]);
    }
    for (int r = 0; r < n2; r++) {
        rtemp.push_back(vals[mid + 1 + r]);
    }

    int i = 0, j = 0, invCount = 0;
    int k = left;

    while ((i < n1) && (j < n2)) {
        if (ltemp[i] <= rtemp[j]) {
            vals[k] = ltemp[i];
            i++;
        } else { 
            vals[k] = rtemp[j];
            j++;
            // since we are merging left and right halves, we can count inversions for the rest of the left half when the right half is smaller
            invCount += (n1 - i); 
        }
        
        k++;
    }

    while (i < n1) {
        vals[k] = ltemp[i];
        i++;
        k++;
    }
    while (j < n2) {
        vals[k] = rtemp[j];
        j++;
        k++;
    }

    return invCount; 
}

// modified merge that also returns inversion count calculations 
template <std::size_t N>
static int mergeCount(std::array<int, N>& vals, int left, int right) {
    int invCount = 0;

    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    invCount += mergeCount(vals, left, mid);
    invCount += mergeCount(vals, mid + 1, right);
    invCount += merge(vals, left, mid, right);
    
    return invCount;
}

template <std::size_t N>
int problem10(std::array<int, N>& vals) {
    // if the list is empty return 0
    if (N == 0) {
        return 0;
    }

    return mergeCount(vals, 0, static_cast<int>(N) - 1);
}

#endif