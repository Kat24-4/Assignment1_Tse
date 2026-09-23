#include <vector>
#include <algorithm>
#include "../include/problem7.h"
using namespace std;

template <std::size_t N>
std::vector<int> problem7(int (&nums)[N], int k) {
    // if the list is empty, reutrn the list back 
    if (N == 0) {
        return nums;
    }

    // sort list to make calculating frequency easier 
    std::sort(nums.begin(), nums.end());

    int key = nums[0];
    int count = 1; 
    std::vector<CountPair> freqPairs;

    // count how many of each number there is and store it in the frequency pair struct 
    for (int i = 1; i < N; i++) {
        if (nums[i] == key) {
            count++;
        } else {
            freqPairs.push_back({key, count});
            key = nums[i];
            count = 1;             
        }
    }
    freqPairs.push_back({key, count});

    // sort frequency pairs (struct has custom comparitor)
    std::sort(freqPairs.begin(), freqPairs.end());
    
    int f = freqPairs.size();
    std::vector<int> final; 
    // add k frequency pairs to final vector for return 
    for(int j = 0; j < k; j++) {
        // if the requested number of values is larger than the number of values, return all values 
        if (j >= f) {
            return final; 
        }
        final.push_back(freqPairs[j].value);
    }

    return final; 
}