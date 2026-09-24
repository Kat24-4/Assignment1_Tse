#include <vector>
#include <iostream>
#ifndef PROBLEM6_H
#define PROBLEM6_H

// custom struct for a point pair (x, y)
struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator<(const Point& other) const {
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }
};


inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::vector<Point> problem6Sort(std::vector<Point> points, int k);

std::vector<Point> problem6Heap(std::vector<Point> points, int k);

#endif