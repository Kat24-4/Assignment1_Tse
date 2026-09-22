#include <vector>
#include "../include/problem9.hpp"
using namespace std;

template <std::size_t N>
int problem9(int (&ints)[N]) {
    if (N == 0) {
        return 0;
    }

    int final = 0;
    int maxIndex, minIndex;
    int temp;
    if (k < N) {
        for (int i = 0; i < k; i++) {
            maxIndex = i;
            for (int j = i + 1; j < N; j++) {
                if (ints[j] > ints[maxIndex]) {
                    maxIndex = j;
                }
            }

            temp = ints[i];
            ints[i] = ints[maxIndex];
            ints[maxIndex] = temp; 
            final = ints[i];
        } else {
            minIndex = 0;
            for (int z = 1; z < N; z++) {
                if (ints[z] < ints[minIndex]) {
                    minIndex = z;
                }
            }
            final = ints[minIndex];
        }
    }

    return final; 
}