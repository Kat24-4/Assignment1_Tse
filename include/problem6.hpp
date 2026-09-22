#include <vector>
#ifndef PROBLEM6_H
#define PROBLEM6_H

struct Point {
    int x;
    int y;
};

std::vector<Point> problem6Sort(std::vector<Point> points, int k);

std::vector<Point> problem6Heap(std::vector<Point> points, int k);

#endif