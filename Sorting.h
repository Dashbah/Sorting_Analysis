//
// Created by Dashbah on 17.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_SORTING_H
#define ALGOSI_KDZ1_SORTINGS_SORTING_H

#include <vector>

class Sorting {
public:
    static int selectionSort(std::vector<int> &vector);
    static int bubbleSort(std::vector<int> &vector);
    static int bubbleSort_Aiverson1(std::vector<int> &vector);
    static int bubbleSortAiverson1And2(std::vector<int> &vector);
    static int insertionSort(std::vector<int> &vector);
    static int binaryInsertionSort(std::vector<int> &vector);
    static int countingSortStable(std::vector<int> &vector);
    static int digitalSort(std::vector<int> &vector);
    static int mergeSort(std::vector<int> &vector);
    static int quickSort(std::vector<int> &vector);
    static int heapSort(std::vector<int> &vector);
    static int shellSort_Tsiur(std::vector<int> &vector);
    static int shellSort_Shell(std::vector<int> &vector);
};


#endif //ALGOSI_KDZ1_SORTINGS_SORTING_H
