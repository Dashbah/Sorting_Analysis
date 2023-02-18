//
// Created by Dashbah on 17.02.2023.
//

#include "Sorting.h"

int Sorting::selectionSort(std::vector<int> &vector) {
    return 0;
}

int Sorting::bubbleSort(std::vector<int> &vector) {
    return vector.size();
}

int Sorting::bubbleSort_Aiverson1(std::vector<int> &vector) {
    return 0;
}

int Sorting::bubbleSortAiverson1And2(std::vector<int> &vector) {
    return 0;
}

int Sorting::insertionSort(std::vector<int> &vector) {
    long long operations = 0;
    for (auto current = 1; current < vector.size(); ++current) {
        ++operations;
        for (auto j = current; j > 0 && vector[j - 1] > vector[j]; --j) {
            ++operations;
            std::swap(vector[j], vector[j - 1]);
        }
    }
    return vector.size();
}

int Sorting::binaryInsertionSort(std::vector<int> &vector) {
    return 0;
}

int Sorting::countingSortStable(std::vector<int> &vector) {
    return 0;
}

int Sorting::digitalSort(std::vector<int> &vector) {
    return 0;
}

int Sorting::mergeSort(std::vector<int> &vector) {
    return 0;
}

int Sorting::quickSort(std::vector<int> &vector) {
    return 0;
}

int Sorting::heapSort(std::vector<int> &vector) {
    return 0;
}

int Sorting::shellSort_Tsiur(std::vector<int> &vector) {
    return 0;
}

int Sorting::shellSort_Shell(std::vector<int> &vector) {
    return 0;
}
