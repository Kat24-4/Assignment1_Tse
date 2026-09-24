#include <vector>
#include <algorithm>
#include "../include/problem6.h"
using namespace std;

// modified merge sort 
static void merge(std::vector<Point>& points, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Point> ltemp(n1), rtemp(n2);

    for (int l = 0; l < n1; l++) {
        ltemp[l] = points[left + l];
    }
    for (int r = 0; r < n2; r++) {
        rtemp[r] = points[mid + 1 + r];
    }

    int i = 0, j = 0, k = left;
    int ldist, rdist; 

    while ((i < n1) && (j < n2)) {
        // calculate distance from origin to use for comparison (x^2 + y^2)
        ldist = (ltemp[i].x * ltemp[i].x) + (ltemp[i].y * ltemp[i].y);
        rdist = (rtemp[j].x * rtemp[j].x) + (rtemp[j].y * rtemp[j].y);

        if (ldist <= rdist) {
            points[k] = ltemp[i];
            i++;
        } else {
            points[k] = rtemp[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        points[k] = ltemp[i];
        i++;
        k++;
    }

    while (j < n2) {
        points[k] = rtemp[j];
        j++;
        k++;
    }
}

static void mergeSort(std::vector<Point>& points, int left, int right) {
    if (left >= right) {
        return; 
    }

    int mid = left + (right - left)/2;
    mergeSort(points, left, mid);
    mergeSort(points, mid + 1, right);
    merge(points, left, mid, right);
}

// Problem 6 solved with a sorting based solution (modified merge sort)
std::vector<Point> problem6Sort(std::vector<Point> points, int k) {
    if (k == 0) {
        return {};
    }
    
    int n = points.size(); 

    // if the number of requested points is equal to or larger than the list, return the whole list 
    if (n <= k) {
        return points;
    }

    // sort points 
    mergeSort(points, 0, n - 1);

    return std::vector<Point>(points.begin(), points.begin() + k);
}

// Problem 6 solved with a heap based solution
std::vector<Point> problem6Heap(std::vector<Point> points, int k) {
    if (k == 0) {
        return {};
    }

    int n = points.size();

    // if the number of requested points is equal to or larger than the list, return the whole list 
    if (n <= k) {
        return points;
    }

    // initalize the min heap and populate it with the points given 
    std::vector<Point> heap = {points[0]};
    int index, currentDist, parentDist; 
    Point temp;
    for (int i = 1; i < n; i++) {
        heap.push_back(points[i]);
        index = heap.size() - 1;
        // calculate the distance from origin to use for comparison 
        currentDist = (heap[index].x * heap[index].x) + (heap[index].y * heap[index].y);
        parentDist = (heap[(index - 1) / 2].x * heap[(index - 1) / 2].x) + (heap[(index - 1) / 2].y * heap[(index - 1) / 2].y);

        // while the parent node is larger than the current node, move it up 
        while ((index > 0) && (currentDist < parentDist)) {
            temp = heap[index];
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp;

            index = (index - 1) / 2;
            parentDist = (heap[(index - 1) / 2].x * heap[(index - 1) / 2].x) + (heap[(index - 1) / 2].y * heap[(index - 1) / 2].y);
        }
    }

    int h = heap.size();
    std::vector<Point> final;
    bool isFixed;
    int left, right, min, lDist, rDist, minDist;
    // once the heap is made, pop off k values to return and re-heapify the min heap
    int finalSize = final.size();
    while (finalSize < k) {
        final.push_back(heap[0]);
        heap[0] = heap[h - 1];
        h--;
        index = 0;
        isFixed = false;
        while (isFixed == false) {
            left = (2 * index) + 1;
            right = (2 * index) + 2;
            min = index; 
            minDist = (heap[min].x * heap[min].x) + (heap[min].y * heap[min].y);

            if (left < h)  {
                lDist = (heap[left].x * heap[left].x) + (heap[left].y * heap[left].y);
                if (lDist < minDist) {
                    min = left;
                }
            }
            if (right < h) {
                rDist = (heap[right].x * heap[right].x) + (heap[right].y * heap[right].y);
                if (rDist < minDist) {
                    min = right; 
                }
            }
            
            if (min != index) {
                temp = heap[min];
                heap[min] = heap[index];
                heap[index] = temp;
                index = min; 
            } else {
                isFixed = true; 
            }
        }
        finalSize = final.size();
    }
    
    return final; 
}