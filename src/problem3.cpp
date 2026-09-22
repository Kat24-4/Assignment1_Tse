#include <string>
#include <vector>
#include "../include/problem3.hpp"
using namespace std;

std::string problem3(std::vector<int> vals) {
    int n = vals.size();

    if (n == 0) {
        return "";
    }

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        bool isLarger = true;

        while ((j >= 0) && (isLarger == true)) {
            if (vals[j] < 0 || vals[j + 1] < 0) {
                throw "Integers must be positive.";
            }
            
            std:string first = std::to_string(vals[j]);
            std:string second = std::to_string(vals[j + 1]);
            std:string current = first + second;
            std:string swapped = second + first;

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

    for (int k = 0; k < n; k++) {
        final.append(std::to_string(vals[k]));
    }

    return final; 
}