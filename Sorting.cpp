//
// Created by Dashbah on 17.02.2023.
//

#include "Sorting.h"
#include "HeapSorted.h"

int Sorting::selectionSort(std::vector<int> &vector) {
    int min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < vector.size() - 1; ++i) {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (int j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx != i) {
            std::swap(vector[min_idx], vector[i]);
        }
    }
}

int Sorting::bubbleSort(std::vector<int> &vector) {
    for (int i = 0; i < vector.size() - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < vector.size() - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
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

int Sorting::countingSort(std::vector<int> &vector) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto value: vector) {
        if (value < min) {
            min = value;
        }
        if (value > max) {
            max = value;
        }
    }
    countingSort1(vector, min, max);
}

int Sorting::digitalSort(std::vector<int> &vector) {
    std::vector<Number> numbers;
    for (auto value: vector) {
        numbers.emplace_back(Number(value));
    }
    for (int i = 0; i < 4; ++i) {
        numbers = countingSortForDigitSort(numbers, i);
    }
    for (size_t i = 0; i < vector.size(); ++i) {
        vector[i] = numbers[i].number;
    }
}

int Sorting::mergeSort(std::vector<int> &vector) {
    mergeSort1(vector.begin(), vector.end());
}

int Sorting::quickSort(std::vector<int> &vector) {
    quickSort1(vector, 0, vector.size());
}

int Sorting::heapSort(std::vector<int> &vector) {
    HeapSorted heap = HeapSorted(vector);
    vector = std::move(heap.getHeap());
    return 0;
}

int Sorting::shellSort_Tsiur(std::vector<int> &vector) {
    return 0;
}

int Sorting::shellSort_Shell(std::vector<int> &vector) {
    return 0;
}

int Sorting::mergeSort1(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
    auto size = std::distance(begin, end);
    if (size < 2) {
        return 0;
    }

    auto mid = begin + size / 2;
    mergeSort1(begin, mid);
    mergeSort1(mid, end);
    merge(begin, mid, end);
}

void Sorting::merge(std::vector<int>::iterator begin, const std::vector<int>::iterator mid,
                    const std::vector<int>::iterator end) {
    std::vector<int> v;
    auto it_l{begin}, it_r{mid};
    auto it_mid{mid}, it_end{end};

    while (it_l != it_mid && it_r != it_end) {
        v.emplace_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
    }
    for (auto i = it_l; i != it_mid; ++i) {
        v.emplace_back(*i);
    }
    for (auto i = it_r; i != it_end; ++i) {
        v.emplace_back(*i);
    }
    for (auto num: v) {
        *begin = num;
        ++begin;
    }
}

void Sorting::countingSort1(std::vector<int> &vec, int min, int max) {
    int k = max - min + 1;
    std::vector<int> b(k);
    for (auto value: vec) {
        ++b[value - min];
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
    }
    std::vector<int> result(vec.size());
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i] - min]] = vec[i];
    }
    vec = std::move(result);
}

std::vector<Number> Sorting::countingSortForDigitSort(const std::vector<Number> &vec, int place, int min, int max) {
    int k = max - min + 1;
    std::vector<int> b(k);
    for (auto &number: vec) {
        ++b[number.bytes[place]];
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
    }

    std::vector<Number> result(vec.size());
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i].bytes[place] - min]] = vec[i];
    }
    return result;
}

int Sorting::partition(std::vector<int> &vec, int start, int end) {
    int pivot = vec[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vec[i] <= pivot) {
            count++;
        }
    }

    // Giving pivot element its correct position
    int pivot_index = start + count;
    std::swap(vec[pivot_index], vec[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivot_index && j > pivot_index) {
        while (vec[i] <= pivot) {
            i++;
        }
        while (pivot < vec[j]) {
            j--;
        }
        if (i < pivot_index && j > pivot_index) {
            std::swap(vec[i++], vec[j--]);
        }
    }

    return pivot_index;
}

void Sorting::quickSort1(std::vector<int> &vector, int start, int end) {
    // base case
    if (start >= end) {
        return;
    }

    // partitioning the array
    int p = partition(vector, start, end);

    // Sorting the left part
    quickSort1(vector, start, p - 1);

    // Sorting the right part
    quickSort1(vector, p + 1, end);
}
