//
// Created by Dashbah on 17.02.2023.
//

#include "Sorting.h"
#include "HeapSorted.h"

long long Sorting::selectionSort(std::vector<int> &vector) {
    long long operations = 0;
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

long long Sorting::bubbleSort(std::vector<int> &vector) {
    for (int i = 0; i < vector.size() - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < vector.size() - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}

long long Sorting::bubbleSort_Iverson1(std::vector<int> &vector) {
    bool t = true;
    for (int i = 0; i < vector.size() - 1; i++) {
        t = false;
        for (int j = 0; j < vector.size() - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                t = true;
            }
        }
        if (!t) {
            break;
        }
    }
}

long long Sorting::bubbleSort_Iverson1And2(std::vector<int> &vector) {
    bool t;
    size_t k = vector.size();
    size_t curr_k;
    for (int i = 0; i < vector.size() - 1; ++i) {
        t = false;
        curr_k = k;
        for (int j = 0; j < curr_k - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                t = true;
                k = j + 1;
            }
        }
        if (!t) {
            break;
        }
    }
}

long long Sorting::insertionSort(std::vector<int> &vector) {
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

long long Sorting::binaryInsertionSort(std::vector<int> &vector) {
    int selected, place_to_insert, j;
    for (auto current = 1; current < vector.size(); ++current) {
        selected = vector[current];
        j = current - 1;

        // find location where selected should be inserted
        place_to_insert = binarySearch(vector, selected, 0, j);

        // Move all elements after location to create space
        while (j >= place_to_insert) {
            vector[j + 1] = vector[j];
            --j;
        }
        vector[j + 1] = selected;
    }
    return vector.size();
}

long long Sorting::countingSort(std::vector<int> &vector) {
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

long long Sorting::digitalSort(std::vector<int> &vector) {
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

long long Sorting::mergeSort(std::vector<int> &vector) {
    mergeSort1(vector.begin(), vector.end());
}

long long Sorting::quickSort(std::vector<int> &vector) {
    quickSort1(vector, 0, vector.size() - 1);
}

long long Sorting::heapSort(std::vector<int> &vector) {
    HeapSorted heap = HeapSorted(vector);
    vector = std::move(heap.getHeap());
    return 0;
}

long long Sorting::shellSort_Tsiur(std::vector<int> &vector) {
    std::vector<int> tsiur = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    for (int gap : tsiur) {
        for (int i = gap; i < vector.size(); ++i) {
            for (int j = i - gap; j >= 0 && vector[j] > vector[j + gap]; j -= gap) {
                std::swap(vector[j], vector[j + gap]);
            }
        }
    }
}

long long Sorting::shellSort_Shell(std::vector<int> &vector) {
    size_t first = 0;
    size_t last = vector.size();
    for (auto d = (first + last) / 2; d != 0; d /= 2) {
        for (auto i = first + d; i != last; ++i) {
            for (auto j = i; j - first >= d && vector[j] < vector[j - d]; j -= d) {
                std::swap(vector[j], vector[j - d]);
            }
        }
    }
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

int Sorting::binarySearch(const std::vector<int> &vec, int item,
                          int low, int high) {
    if (high <= low)
        return (item > vec[low]) ?
               (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == vec[mid])
        return mid + 1;

    if (item > vec[mid])
        return binarySearch(vec, item,
                            mid + 1, high);
    return binarySearch(vec, item, low,
                        mid - 1);
}