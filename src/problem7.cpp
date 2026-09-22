#include <vector>
#include <algorithm>
#include "../include/problem7.hpp"
using namespace std;

template <std::size_t N>
std::vector<int> problem7(int (&nums)[N], int k) {
    if (N == 0) {
        return nums;
    }

    std::sort(nums.begin(), nums.end());

    int key = nums[0];
    int count = 1; 
    std::vector<CountPair> freqPairs;

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

    std::sort(freqPairs.begin(), freqPairs.end());
    
    int f = freqPairs.size();
    std::vector<int> final; 
    for(int j = 0; j < k; j++) {
        if (j >= f) {
            return final; 
        }
        final.push_back(freqPairs[j].value);
    }

    return final; 
}