#include <string>
#include <vector>
#include "../include/problem3.hpp"
using namespace std;

std::string problem3(std::vector<int> vals) {
    int n = vals.size();

    // if the vector is empty, return an empty string
    if (n == 0) {
        return "";
    }

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        bool isLarger = true;

        while ((j >= 0) && (isLarger == true)) {
            // if a given integer is negative, throw an error
            if (vals[j] < 0 || vals[j + 1] < 0) {
                throw "Integers must be positive.";
            }

            // pull current and next value and create the two potential numers 
            std:string first = std::to_string(vals[j]);
            std:string second = std::to_string(vals[j + 1]);
            std:string current = first + second;
            std:string swapped = second + first;

            // keep the order for whichever pair order creates the largest integer 
            if (std::stoi(swapped) > std::stoi(current)) {
                int temp = vals[j];
                vals[j] = vals[j + 1];
                vals[j + 1] = temp;
                
                j--;
            } else {
                isLarger = false; 
            }
        }
    }

    std::string final = "";

    // turn the list into a single string to be returned 
    for (int k = 0; k < n; k++) {
        final.append(std::to_string(vals[k]));
    }

    return final; 
}