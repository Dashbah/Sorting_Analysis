//
// Created by Dashbah on 17.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_SORTING_H
#define ALGOSI_KDZ1_SORTINGS_SORTING_H

#include <vector>
#include "Number.h"

class Sorting {
public:
    static long long selectionSort(std::vector<int> &vector);

    static long long bubbleSort(std::vector<int> &vector);

    static long long bubbleSort_Iverson1(std::vector<int> &vector);

    static long long bubbleSort_Iverson1And2(std::vector<int> &vector);

    static long long insertionSort(std::vector<int> &vector);

    static long long binaryInsertionSort(std::vector<int> &vector);

    static long long countingSort(std::vector<int> &vector);

    static long long digitalSort(std::vector<int> &vector);

    static long long mergeSort(std::vector<int> &vector);

    static long long quickSort(std::vector<int> &vector);

    static long long heapSort(std::vector<int> &vector);

    static long long shellSort_Tsiur(std::vector<int> &vector);

    static long long shellSort_Shell(std::vector<int> &vector);

private:
    static int mergeSort1(std::vector<int>::iterator begin, std::vector<int>::iterator end,
                          long long &operations);

    static void merge(std::vector<int>::iterator begin, std::vector<int>::iterator mid,
                      std::vector<int>::iterator end, long long &operations);

    static void countingSort1(std::vector<int> &vec, int min, int max, long long &operations);

    static std::vector<Number>
    countingSortForDigitSort(const std::vector<Number> &vec, int place, long long &operations,
                             int min = 0,
                             int max = 255);

    static void quickSort1(std::vector<int> &vector, int start, int end, long long &operations);

    static int partition(std::vector<int> &vec, int start, int end, long long &operations);

    static int binarySearch(const std::vector<int> &vec, int item,
                            int low, int high, int &operations);
};


#endif //ALGOSI_KDZ1_SORTINGS_SORTING_H
