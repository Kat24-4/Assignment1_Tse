#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
#include "../include/problem4.hpp"
using namespace std;

std::vector<std::string> problem4(std::vector<std::string> words) {
    int n = words.size();
    if (n == 0) {
        return words;
    }

    std::vector<std::string> keys; 
    std::unordered_map<std::string, std::vector<std::string>> map; 

    std::string currentWord;
    std::vector<char> chars;
    int m;
    bool wasAdded;
    std::string currentKey;

    for (int i = 0; i < n; i++) {
        currentWord = words[i];

        std::copy(currentWord.begin(), currentWord.end(), chars);
        std::transform(chars.begin(), chars.end(), chars.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        std::sort(chars.begin(), chars.end());

        m = 0;
        wasAdded = false;
        currentKey.assign(chars.begin(), chars.end());
        while((m < keys.size()) && (wasAdded == false)) {
            if ((currentKey.length() == keys[m].length()) && (currentKey == keys[m])) {
                map[currentKey].push_back(currentWord);
                wasAdded = true;
            }
            m++;
        }

        if(wasAdded == false) {
            map[currentKey] = {currentWord};
            keys.push_back(currentKey);
        }
    }

    std::vector<std::string> final;
    for(int j = 0; j < keys.size(); j++) {
        final.insert(final.end(), map[keys[j]].begin(), map[keys[j]].end());
    }

    return final; 
}