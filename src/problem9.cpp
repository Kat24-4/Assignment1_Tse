#include <vector>
#include "../include/problem9.h"
using namespace std;


int problem9(int ints[], int N, int k) {
    // if list is empty, return 0
    if (N == 0) {
        return 0;
    }

    int final = 0;
    int maxIndex, minIndex;
    int temp;
    if (k < static_cast<int>(N)) { // only traverse if k is not larger than the size of the array
        for (int i = 0; i < k; i++) { // loop until you found the kth-largest element 
            maxIndex = i;
            // find max index and begin sorting the list 
            for (int j = i + 1; j < static_cast<int>(N); j++) {
                if (ints[j] > ints[maxIndex]) {
                    maxIndex = j;
                }
            }

            temp = ints[i];
            ints[i] = ints[maxIndex];
            ints[maxIndex] = temp; 
            final = ints[i];
        }
    } else { // if k is larger or equal to the size of the given array, return the minimum value 
        minIndex = 0;
        for (int z = 1; z < static_cast<int>(N); z++) {
            if (ints[z] < ints[minIndex]) {
                minIndex = z;
            }
        }
        final = ints[minIndex];
    }

    return final; 
}