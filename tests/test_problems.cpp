#include "test_framework.h"
#include <vector>
#include <array>
#include <string>
#include <chrono>
#include <thread>

//files to be tested
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

void testProblem1() {
    std::cout << "Testing Problem 1\n";
    std::cout << "-----------------\n";

    //Test 1
    Interval intvs1[4] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<Interval> expt1 = {{1, 6}, {8, 10}, {15, 18}}; 

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Interval> res1 = problem1(intvs1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {1, 3}, {2, 6}, {8, 10}, {15, 18}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1);
    std::cout << "\n";

    //Test 2
    Interval intvs2[5] = {{5, 10}, {1, 2}, {9, 15}, {2, 3}, {15, 20}};
    std::vector<Interval> expt2 = {{1, 3}, {5, 20}}; 

    start = std::chrono::high_resolution_clock::now();
    std::vector<Interval> res2 = problem1(intvs2);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {5, 10}, {1, 2}, {9, 15}, {2, 3}, {15, 20}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt2, res2);
    std::cout << "\n";

    //Test 3
    Interval intvs3[1] = {};
    std::vector<Interval> expt3 = {}; 

    start = std::chrono::high_resolution_clock::now();
    std::vector<Interval> res3 = problem1(intvs3);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem2() {
    
}

void testProblem3() {
    
}

void testProblem4() {
    
}

void testProblem5() {
    
}

void testProblem6() {
    
}

void testProblem7() {
    
}

void testProblem8() {
    
}

void testProblem9() {
    
}

void testProblem10() {
    
}

int main () {

}