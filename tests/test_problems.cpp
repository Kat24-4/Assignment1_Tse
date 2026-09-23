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
    Interval intvs1[5] = {{1, 3}, {1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<Interval> expt1 = {{1, 6}, {8, 10}, {15, 18}}; 

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Interval> res1 = problem1(intvs1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {1, 3}, {2, 6}, {8, 10}, {15, 18}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1);

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
    std::cout << "Testing Problem 2\n";
    std::cout << "-----------------\n";

    // Test 1
    int ints1C[6] = {2, 0, 2, 1, 1, 0};
    int ints1D[6] = {2, 0, 2, 1, 1, 0};
    int expt1[6] = {0, 0, 1, 1, 2, 2};

    auto start = std::chrono::high_resolution_clock::now();
    problem2Count(ints1C);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {2, 0, 2, 1, 1, 0}";
    std::cout << "Count Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_ARRAY_EQ(expt1, ints1C);

    start = std::chrono::high_resolution_clock::now();
    problem2Dutch(ints1D);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "One-Pass Dutch National Flag Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_ARRAY_EQ(expt1, ints1D);

    // Test 2
    int ints2C[1] = {};
    int ints2D[1] = {};
    int expt2[1] = {};

    start = std::chrono::high_resolution_clock::now();
    problem2Count(ints2C);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {}";
    std::cout << "Count Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_ARRAY_EQ(expt2, ints2C);

    start = std::chrono::high_resolution_clock::now();
    problem2Dutch(ints2D);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "One-Pass Dutch National Flag Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_ARRAY_EQ(expt2, ints2D);

    // Test 3
    int ints3C[3] = {1, 1, 1};
    int ints3D[3] = {1, 1, 1};
    int expt3[3] = {1, 1, 1};

    start = std::chrono::high_resolution_clock::now();
    problem2Count(ints3C);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {1, 1, 1}";
    std::cout << "Count Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_ARRAY_EQ(expt3, ints3C);

    start = std::chrono::high_resolution_clock::now();
    problem2Dutch(ints3D);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "One-Pass Dutch National Flag Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_ARRAY_EQ(expt3, ints3D);
    std::cout << "\n";
}

void testProblem3() {
    std::cout << "Testing Problem 3\n";
    std::cout << "-----------------\n";
    
    //Test 1
    std::vector<int> vals1 = {3, 30, 34, 5, 9};
    std::string expt1 = "9534330";

    auto start = std::chrono::high_resolution_clock::now();
    std::string res1 = problem3(vals1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {3, 30, 34, 5, 9}";
    std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt1, res1);

    //Test 2
    std::vector<int> vals2 = {};
    std::string expt2 = "";

    start = std::chrono::high_resolution_clock::now();
    std::string res2 = problem3(vals2);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {}";
    std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt2, res2);

    //Test 3
    std::vector<int> vals3 = {0, 0, 0, 0};
    std::string expt3 = "0";

    start = std::chrono::high_resolution_clock::now();
    std::string res3 = problem3(vals1);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {0, 0, 0, 0}";
    std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem4() {
    std::cout << "Testing Problem 4\n";
    std::cout << "-----------------\n";

    //Test 1
    std::vector<std::string> words1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> expt1 = {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<std::string>> res1 = problem4(words1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"}";
    std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1);

    //Test 2
    std::vector<std::string> words2 = {"", ""};
    std::vector<std::vector<std::string>> expt2 = {{"", ""}};

    start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<std::string>> res2 = problem4(words2);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {\"\", \"\"}";
    std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt2, res2);

    //Test 3
    std::vector<std::string> words3 = {"ab", "ba", "abc"};
    std::vector<std::vector<std::string>> expt3 = {{"ab", "ba"}, {"abc"}};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<std::string>> res3 = problem4(words1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {\"ab\", \"ba\", \"abc\"}";
    std::cout << "Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem5() {
    std::cout << "Testing Problem 5\n";
    std::cout << "-----------------\n";

    //Test 1
    Interval intvs1[3] = {{0, 24}, {5, 10}, {15, 20}};
    bool expt1 = false; 

    auto start = std::chrono::high_resolution_clock::now();
    bool res1 = problem5(intvs1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {0, 24}, {5, 10}, {15, 20}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt1, res1);

    //Test 2
    Interval intvs2[1] = {};
    bool expt2 = true; 

    start = std::chrono::high_resolution_clock::now();
    bool res2 = problem5(intvs2);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt2, res2);

    //Test 3
    Interval intvs3[2] = {{5, 10}, {1, 5}};
    bool expt3 = true; 

    start = std::chrono::high_resolution_clock::now();
    bool res3 = problem5(intvs3);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {5, 10}, {1, 5}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem6() {
    std::cout << "Testing Problem 6\n";
    std::cout << "-----------------\n";

    // Test 1
    int k = 2; 
    std::vector<Point> points1S = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    std::vector<Point> points1H = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    std::vector<Point> expt1 = {{0, 1}, {-2, 2}};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Point> res1S = problem6Sort(points1S, k);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {1, 3}, {-2, 2}, {5, 8}, {0, 1}";
    std::cout << "Sort Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1S);

    start = std::chrono::high_resolution_clock::now();
    std::vector<Point> res1H = problem6Heap(points1H, k);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Heap Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1H);

    // Test 2
    k = 3; 
    std::vector<Point> points2S = {{3, 3}, {5, -1}, {-2, 4}};
    std::vector<Point> points2H = {{3, 3}, {5, -1}, {-2, 4}};
    std::vector<Point> expt2 = {{3, 3}, {5, -1}, {-2, 4}};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Point> res2S = problem6Sort(points2S, k);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {3, 3}, {5, -1}, {-2, 4}";
    std::cout << "Sort Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt2, res2S);

    start = std::chrono::high_resolution_clock::now();
    std::vector<Point> res2H = problem6Heap(points2H, k);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Heap Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt2, res2H);

    // Test 3
    k = 0; 
    std::vector<Point> points3S = {{1, 1}};
    std::vector<Point> points3H = {{1, 1}};
    std::vector<Point> expt3 = {};

    start = std::chrono::high_resolution_clock::now();
    std::vector<Point> res3S = problem6Sort(points3S, k);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {1, 1}";
    std::cout << "Sort Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt3, res3S);

    start = std::chrono::high_resolution_clock::now();
    std::vector<Point> res3H = problem6Heap(points3H, k);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Heap Execution Time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt3, res3H);
    std::cout << "\n";
}

void testProblem7() {
    std::cout << "Testing Problem 7\n";
    std::cout << "-----------------\n";

    //Test 1
    int k = 2;
    int nums1[6] = {1, 2, 1, 1, 3, 2};
    std::vector<int> expt1 = {1, 2}; 

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res1 = problem7(nums1, k);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {1, 2, 1, 1, 3, 2}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1);

    //Test 2
    k = 3;
    int nums2[7] = {4, 5, 6, 6, 5, 4, 7};
    std::vector<int> expt2 = {4, 5, 6}; 

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res2 = problem7(nums2, k);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {4, 5, 6, 6, 5, 4, 7}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt2, res2);

    //Test 3
    k = 1;
    int nums3[1] = {};
    std::vector<int> expt3 = {}; 

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res3 = problem7(nums3, k);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem8() {
    std::cout << "Testing Problem 8\n";
    std::cout << "-----------------\n";

    //Test 1
    std::vector<std::vector<int>> arrs1 = {{1, 4, 7}, {2, 5, 8, 9}, {3,6}};
    std::vector<int> expt1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res1 = problem8(arrs1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {1, 4, 7}, {2, 5, 8, 9}, {3,6}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt1, res1);

    //Test 2
    std::vector<std::vector<int>> arrs2 = {};
    std::vector<int> expt2 = {};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res2 = problem8(arrs2);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt2, res2);

    //Test 3
    std::vector<std::vector<int>> arrs3 = {{2, 2, 3}, {2, 2}, {1}};
    std::vector<int> expt3 = {1, 2, 2, 2, 2, 3};

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> res3 = problem8(arrs3);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {2, 2, 3}, {2, 2}, {1}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_VEC_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem9() {
    std::cout << "Testing Problem 9\n";
    std::cout << "-----------------\n";

    //Test 1
    int k = 2;
    int nums1[6] = {3, 2, 1, 5, 6, 4};
    int expt1 = 5; 

    auto start = std::chrono::high_resolution_clock::now();
    int res1 = problem9(nums1, k);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {3, 2, 1, 5, 6, 4}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt1, res1);

    //Test 2
    k = 3;
    int nums2[6] = {3, 3, 3, 2, 1, 0};
    int expt2 = 3; 

    start = std::chrono::high_resolution_clock::now();
    int res2 = problem9(nums2, k);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {3, 3, 3, 2, 1, 0}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt2, res2);

    //Test 3
    k = 5;
    int nums3[4] = {3, 7, 1, 11};
    int expt3 = 1; 

    start = std::chrono::high_resolution_clock::now();
    int res3 = problem9(nums3, k);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {3, 7, 1, 11}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt3, res3);
    std::cout << "\n";
}

void testProblem10() {
    std::cout << "Testing Problem 10\n";
    std::cout << "-----------------\n";

    //Test 1
    int nums1[4] = {8, 4, 2, 1};
    int expt1 = 6; 

    auto start = std::chrono::high_resolution_clock::now();
    int res1 = problem10(nums1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 1: {8, 4, 2, 1}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt1, res1);

    //Test 2
    int nums2[5] = {2, 4, 1, 3, 5};
    int expt2 = 3; 

    auto start = std::chrono::high_resolution_clock::now();
    int res2 = problem10(nums2);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 2: {2, 4, 1, 3, 5}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt2, res2);

    //Test 3
    int nums3[1] = {};
    int expt3 = 0; 

    auto start = std::chrono::high_resolution_clock::now();
    int res3 = problem10(nums3);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Input 3: {}";
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    CHECK_EQ(expt3, res3);
    std::cout << "\n";
}

int main () {
    std::cout << "Assignment 1 Test Suite\n";
    std::cout << "-----------------------\n";

    testProblem1();
    testProblem2();
    testProblem3();
    testProblem4();
    testProblem5();
    testProblem6();
    testProblem7();
    testProblem8();
    testProblem9();
    testProblem10();

    return report_results();

}