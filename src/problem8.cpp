#include <vector>
#include "../include/problem8.hpp"
using namespace std;

// function to merge two sorted arrays into a single sorted array 
static std::vector<int> mergeArrays(std::vector<int> arr1, std::vector<int> arr2) {
    int N1 = arr1.size();
    int N2 = arr2.size();
    int index1 = 0, index2 = 0;
    std::vector<int> final; 

    // go through each list and add the smaller value to the final list first 
    while ((index1 < N1) && (index2 < N2)) {
        if (arr1[index1] <= arr2[index2]) {
            final.push_back(arr1[index1]);
            index1++;
        } else {
            final.push_back(arr2[index2]);
            index2++;
        }
    }

    // add in any remaining values from the lists 
    while(index1 < N1) {
        final.push_back(arr1[index1]);
        index1++;
    }
    while(index2 < N2) {
        final.push_back(arr2[index2]);
        index2++;
    }

    return final; 
}

std::vector<int> problem8(std::vector<std::vector<int>> arrays) {
    int k = arrays.size();
    std::vector<int> final;

    // if the given list of arrays is empty return an empty vector 
    if (k == 0) {
        return final;
    }
    
    final = arrays[0]; 

    // merge all arrays 
    for (int i = 1; i < k; i++) {
        final = mergeArrays(final, arrays[i]);
    }

    return final; 
}
