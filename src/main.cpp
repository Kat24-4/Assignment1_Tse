#include <iostream>
#include <chrono>
#include <sstream>
#include "../include/problem1.h"
#include "../include/problem2.h"
#include "../include/problem3.h"
#include "../include/problem4.h"
#include "../include/problem5.h"
#include "../include/problem6.h"
#include "../include/problem7.h"
#include "../include/problem8.h"
#include "../include/problem9.h"
#include "../include/problem10.h"
using namespace std;

int main() {
    int problem; 

    std::cout << "EECE 7205 Assignment 1 - Katherine Tse" << endl; 
    std::cout << "--------------------------------------" << endl;
    std::cout << "Please input a problem number to run {1 - 10}: ";
    std::cin >> problem; 

    switch (problem) {
        case 1: {
            Interval interval;
            std::vector<Interval> intervals;
            std::cout << "Please enter your intervals one at a time with the values seperated by a space [ex. 1 2] (enter x to finish): " << endl; 
            
            while (std::cin >> interval.start >> interval.end) {
                intervals.push_back(interval);
            }

            std::cout << "Running Problem 1..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<Interval> res = problem1(intervals.data(), intervals.size());
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "Result: ";
            for (const auto& iv : res) {
                std::cout << "{" << iv.start << ", " << iv.end << "} ";
            }
            std::cout << std::endl;
            std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
            break;
        } 
        case 2: {
            std::cout << "Please enter 0, 1, and 2s seperated by a space and ending with an x:" << endl;
            std::vector<int> numsC;
            int temp;

            while (std::cin >> temp) {
                numsC.push_back(temp);
            }

            std::vector<int> numsD = numsC;
            std::cout << "Running Problem 2 ..." << endl;

            std::cout << "Count Solution:" << endl;
            auto start = std::chrono::high_resolution_clock::now();
            problem2Count(numsC.data(), numsC.size());
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "{";
            for (std::size_t i = 0; i < numsC.size(); ++i) {
            std::cout << numsC[i] << " ";
            }
            std::cout << "}" << endl;
            std::cout << "Count Execution Time: " << duration.count() << "ms" << std::endl;

            std::cout << "One-Pass Dutch National Flag Solution:" << endl;
            start = std::chrono::high_resolution_clock::now();
            problem2Dutch(numsD.data(), numsD.size());
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "{";
            for (std::size_t i = 0; i < numsD.size(); ++i) {
            std::cout << numsD[i] << " ";
            }
            std::cout << "}" << endl;
            std::cout << "One-Pass Dutch National Flag Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Please enter a list of integers with spaces inbetween and ending with an x: " << endl;
            std::vector<int> nums;
            int temp;

            while (std::cin >> temp) {
                nums.push_back(temp);
            }

            std::cout << "Running Problem 3..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::string res = problem3(nums);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            
            std::cout << "Result: ";
            std::cout << "{";
            for (std::size_t i = 0; i < res.size(); ++i) {
            std::cout << res[i] << " ";
            }
            std::cout << "}" << endl;
            std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 4: {
            std::cout << "Please enter a list of words with spaces inbetween (click enter and then press Ctrl+D): " << endl;
            std::vector<std::string> words;
            std::string temp;

            while (std::cin >> temp) {
                words.push_back(temp);
            }

            std::cout << "Running Problem 4..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<std::vector<std::string>> res = problem4(words);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            
            std::cout << "Result: ";
            std::cout << "{";
            for (std::size_t i = 0; i < res.size(); ++i) {
                std::cout << "{";
                for (std::size_t j = 0; j < res[i].size(); ++j) {
                    std::cout << res[i][j];
                    if (j != res[i].size() - 1) std::cout << ", ";
                }
                std::cout << "}";
                if (i != res.size() - 1) std::cout << ", ";
            }
            std::cout << "}" << std::endl;
            std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 5: {
            Interval interval;
            std::vector<Interval> intervals;
            std::cout << "Please enter your intervals one at a time with the values seperated by a space [ex. 1 2] (enter x to finish): " << endl; 
            
            while (std::cin >> interval.start >> interval.end) {
                intervals.push_back(interval);
            }

            std::cout << "Running Problem 5..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            bool res = problem5(intervals.data(), intervals.size());
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "Result: " << res << endl;
            std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 6: {
            Point point;
            std::vector<Point> pointsS;
            std::cout << "Please enter your points one at a time with the values seperated by a space [ex. 1 2] (enter x to finish): " << endl; 
            
            while (std::cin >> point.x >> point.y) {
                pointsS.push_back(point);
            }

            std::vector<Point> pointsH = pointsS;

            int k; 
            std::cout << "Please enter how many points to return: " << endl; 
            std::cin >> k;

            std::cout << "Running Problem 6..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<Point> resS = problem6Sort(pointsS, k);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "Sort Solution:" << endl;
            for (const auto& iv : resS) {
                std::cout << "{" << iv.x << ", " << iv.y << "} ";
            }
            std::cout << std::endl;
            std::cout << "Execution time: " << duration.count() << "ms" << std::endl;

            start = std::chrono::high_resolution_clock::now();
            std::vector<Point> resH = problem6Heap(pointsH, k);
            end = std::chrono::high_resolution_clock::now();
            duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "Heap Solution:" << endl;
            for (const auto& iv : resH) {
                std::cout << "{" << iv.x << ", " << iv.y << "} ";
            }
            std::cout << std::endl;
            std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 7: {
            std::cout << "Please enter a list of integers with spaces inbetween and ending with an x: " << endl;
            std::vector<int> nums;
            int temp;

            while (std::cin >> temp) {
                nums.push_back(temp);
            }

            int k; 
            std::cout << "Please enter how many points to return: " << endl; 
            std::cin >> k;

            std::cout << "Running Problem 7..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<int> res = problem7(nums.data(), nums.size(), k);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            
            std::cout << "Result: ";
            std::cout << "{";
            for (std::size_t i = 0; i < res.size(); ++i) {
            std::cout << res[i] << " ";
            }
            std::cout << "}" << endl;
            std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 8: {
            std::cout << "Please enter sorted lists of integers, one list per line, "
                      << "with spaces between numbers and ending each line with an x." << endl;
            std::cout << "Enter an empty line (just x) when you're done adding lists." << endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::vector<std::vector<int>> arrays;
            std::string line;

            while (std::getline(std::cin, line)) {
                std::istringstream iss(line);
                std::vector<int> current;
                int num;

                while (iss >> num) {
                    current.push_back(num);
                }

                    // if the line was empty (just "x" or nothing before it), stop reading arrays
                if (current.empty()) {
                    break;
                }

                arrays.push_back(current);
            }

            std::cout << "Running Problem 8..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<int> res = problem8(arrays);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << "Result: ";
            std::cout << "{";
            for (std::size_t i = 0; i < res.size(); ++i) {
                std::cout << res[i] << " ";
            }
            std::cout << "}" << endl;
            std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 9: {
            std::cout << "Please enter a list of integers with spaces inbetween and ending with an x: " << endl;
            std::vector<int> nums;
            int temp;

            while (std::cin >> temp) {
                nums.push_back(temp);
            }

            int k; 
            std::cout << "Please enter how many points to return: " << endl; 
            std::cin >> k;

            std::cout << "Running Problem 9..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            int res = problem9(nums.data(), nums.size(), k);
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            
            std::cout << "Result: ";
            std::cout << res << endl;
            std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        case 10: {
            std::cout << "Please enter a list of integers with spaces inbetween and ending with an x: " << endl;
            std::vector<int> nums;
            int temp;

            while (std::cin >> temp) {
                nums.push_back(temp);
            }

            int k; 
            std::cout << "Please enter how many points to return: " << endl; 
            std::cin >> k;

            std::cout << "Running Problem 10..." << endl;
            auto start = std::chrono::high_resolution_clock::now();
            int res = problem10(nums.data(), nums.size());
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            
            std::cout << "Result: ";
            std::cout << res << endl;
            std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
            break;
        }
        default:
            std::cout << "Invalid problem number" << endl;
            break;
    }
}