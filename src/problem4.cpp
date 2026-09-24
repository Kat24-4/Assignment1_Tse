#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
#include "../include/problem4.h"
using namespace std;

std::vector<std::vector<std::string>> problem4(std::vector<std::string> words) {
    // if given vector is empty, return the empty vector back 
    std::vector<std::vector<std::string>> final;

    int n = words.size();
    if (n == 0) {
        return final;
    }

    // make variables to track the keys and the hashmap itself 
    std::vector<std::string> keys; 
    std::unordered_map<std::string, std::vector<std::string>> map; 

    std::string currentWord;
    std::vector<char> chars;
    int m;
    bool wasAdded;
    std::string currentKey;
    int keySize;

    for (int i = 0; i < n; i++) {
        currentWord = words[i];
        chars.clear();

        // take the current word, ensure all letters are lowercase, and sort the letters to generate the anagram key 
        std::copy(currentWord.begin(), currentWord.end(), std::back_inserter(chars));
        std::transform(chars.begin(), chars.end(), chars.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        std::sort(chars.begin(), chars.end());

        m = 0;
        wasAdded = false;
        currentKey.assign(chars.begin(), chars.end());
        // run through the list of keys to check if the key for the word exists in the hashmap already
        keySize = keys.size();
        while((m < keySize) && (wasAdded == false)) {
            // if key already exists, add word to the array of anagrams 
            if ((currentKey.length() == keys[m].length()) && (currentKey == keys[m])) {
                map[currentKey].push_back(currentWord);
                wasAdded = true;
            }
            m++;
        }

        // if the key did not exist already, add it as a new hashmap entry 
        if(wasAdded == false) {
            map[currentKey] = {currentWord};
            keys.push_back(currentKey);
            keySize = keys.size();
        }
    }

    // combine all of the anagram lists into a final vector to return 
    for(int j = 0; j < keySize; j++) {
        final.push_back(map[keys[j]]);
    }

    return final; 
}