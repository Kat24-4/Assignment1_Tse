#include <vector>
#include "../include/problem8.hpp"
using namespace std;

static std::vector<int> mergeArrays(std::vector<int> arr1, std::vector<int> arr2) {
    int N1 = arr1.size();
    int N2 = arr2.size();
    int index1 = 0, index2 = 0;
    std::vector<int> final; 

    while ((index1 < N1) && (index2 < N2)) {
        if (arr1[index1] <= arr2[index2]) {
            final.push_back(arr1[index1]);
            index1++;
        } else {
            final.push_back(arr2[index2]);
            index2++;
        }
    }

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
    
    std::vector<int> final = arrays[0]; 

    for (int i = 1; i < k; i++) {
        final = mergeArrays(final, arrays[i]);
    }

    return final; 
}
