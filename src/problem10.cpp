#include <vector>
#include "../include/problem10.h"
using namespace std;


// modified merge sort to count inversions
static int merge(int vals[], int N, int left, int mid, int right) {
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
static int mergeCount(int vals[], int N, int left, int right) {
    int invCount = 0;

    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    invCount += mergeCount(vals, N, left, mid);
    invCount += mergeCount(vals, N, mid + 1, right);
    invCount += merge(vals, N, left, mid, right);
    
    return invCount;
}
 

int problem10(int vals[], int N) {
    // if the list is empty return 0
    if (N == 0) {
        return 0;
    }

    return mergeCount(vals, N, 0, static_cast<int>(N) - 1);
}