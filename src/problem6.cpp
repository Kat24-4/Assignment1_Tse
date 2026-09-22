#include <vector>
#include "../include/problem6.hpp"
using namespace std;

static void merge(std::vector<Point> points, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Point> ltemp, rtemp;

    for (int l = 0; l < n1; l++) {
        ltemp[l] = points[left + l];
    }
    for (int r = 0; r < n2; r++) {
        rtemp[r] = points[mid + 1 + r];
    }

    int i = 0, j = 0, k = left;
    int ldist, rdist; 

    while ((i < n1) && (j < n2)) {
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

static void mergeSort(std::vector<Point> points, int left, int right) {
    if (left >= right) {
        return; 
    }

    int mid = left + (right - left)/2;
    mergeSort(points, left, mid);
    mergeSort(points, mid + 1, right);
    merge(points, left, mid, right);
}

std::vector<Point> problem6Sort(std::vector<Point> points, int k) {
    int n = points.size(); 
    mergeSort(points, 0, n - 1);

    if (n <= k) {
        return points;
    }

    return std::vector<Point>(points.begin(), points.begin() + k);
}

std::vector<Point> problem6Heap(std::vector<Point> points, int k) {
    int n = points.size();

    if (n <= k) {
        return points;
    }

    std::vector<Point> heap = {points[0]};
    int index, currentDist, parentDist; 
    Point temp;
    for (int i = 1; i < n; i++) {
        heap.push_back(points[i]);
        index = heap.size() - 1;
        currentDist = (heap[index].x * heap[index].x) + (heap[index].y * heap[index].y);
        parentDist = (heap[(index - 1) / 2].x * heap[(index - 1) / 2].x) + (heap[(index - 1) / 2].y * heap[(index - 1) / 2].y);

        while ((index > 0) && (currentDist < parentDist)) {
            temp = heap[index];
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp;

            index = (index - 1) / 2;
            currentDist = parentDist;
            parentDist = (heap[(index - 1) / 2].x * heap[(index - 1) / 2].x) + (heap[(index - 1) / 2].y * heap[(index - 1) / 2].y);
        }
    }

    int h = heap.size();
    std::vector<Point> final;
    bool isFixed;
    int left, right, min, lDist, rDist, minDist;
    while (final.size() < k) {
        final.push_back(heap[0]);
        heap[0] = heap[h - 1];
        h--;
        index = 0;
        isFixed = false;
        while (isFixed == false) {
            left = (2 * index) + 1;
            right = (2 * index) + 2;
            min = index; 
            lDist = (heap[left].x * heap[left].x) + (heap[left].y * heap[left].y);
            rDist = (heap[right].x * heap[right].x) + (heap[right].y * heap[right].y);
            minDist = (heap[min].x * heap[min].x) + (heap[min].y * heap[min].y);

            if ((left < h) && (lDist < minDist)) {
                min = left;
            }
            if ((right < h) && (rDist < minDist)) {
                min = right; 
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
    }
    
    return final; 
}