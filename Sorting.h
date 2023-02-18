//
// Created by Dashbah on 17.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_SORTING_H
#define ALGOSI_KDZ1_SORTINGS_SORTING_H

#include <vector>
#include "Number.h"

class Sorting {
public:
    static int selectionSort(std::vector<int> &vector);

    static int bubbleSort(std::vector<int> &vector);

    static int bubbleSort_Iverson1(std::vector<int> &vector);

    static int bubbleSort_Iverson1And2(std::vector<int> &vector);

    static int insertionSort(std::vector<int> &vector);

    static int binaryInsertionSort(std::vector<int> &vector);

    static int countingSort(std::vector<int> &vector);

    static int digitalSort(std::vector<int> &vector);

    static int mergeSort(std::vector<int> &vector);

    static int quickSort(std::vector<int> &vector);

    static int heapSort(std::vector<int> &vector);

    static int shellSort_Tsiur(std::vector<int> &vector);

    static int shellSort_Shell(std::vector<int> &vector);

private:
    static int mergeSort1(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    static void merge(std::vector<int>::iterator begin, std::vector<int>::iterator mid,
                      std::vector<int>::iterator end);

    static void countingSort1(std::vector<int> &vec, int min, int max);

    static std::vector<Number> countingSortForDigitSort(const std::vector<Number> &vec, int place, int min = 0,
                                                        int max = 255);

    static void quickSort1(std::vector<int> &vector, int start, int end);

    static int partition(std::vector<int> &vec, int start, int end);
};


#endif //ALGOSI_KDZ1_SORTINGS_SORTING_H
