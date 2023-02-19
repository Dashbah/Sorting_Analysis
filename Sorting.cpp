//
// Created by Dashbah on 17.02.2023.
//

#include "Sorting.h"
#include "HeapSorted.h"

long long Sorting::selectionSort(std::vector<int> &vector) {
    long long operations = 0;
    int min_idx;
    ++operations;
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < vector.size() - 1; ++i) {
        operations += 4;
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        ++operations;
        for (int j = i + 1; j < vector.size(); j++) {
            operations += 3;
            if (vector[j] < vector[min_idx]) {
                ++operations;
                min_idx = j;
            }
            operations += 3;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx != i) {
            std::swap(vector[min_idx], vector[i]);
            operations += 7;
        }
        ++operations;
    }
    return operations;
}

long long Sorting::bubbleSort(std::vector<int> &vector) {
    long long operations = 0;
    for (int i = 0; i < vector.size() - 1; i++) {
        operations += 4;
        // Last i elements are already in place
        for (int j = 0; j < vector.size() - i - 1; j++) {
            operations += 5;
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                operations += 9;
            }
            operations += 4;
        }
    }
    return operations;
}

long long Sorting::bubbleSort_Iverson1(std::vector<int> &vector) {
    long long operations = 0;
    bool t = true;
    ++operations;
    for (int i = 0; i < vector.size() - 1; i++) {
        t = false;
        operations += 5;
        for (int j = 0; j < vector.size() - i - 1; ++j) {
            operations += 5;
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                t = true;
                operations += 10;
            }
            operations += 4;
        }
        if (!t) {
            break;
        }
        ++operations;
    }
    return operations;
}

long long Sorting::bubbleSort_Iverson1And2(std::vector<int> &vector) {
    long long operations = 0;
    bool t;
    size_t k = vector.size();
    size_t curr_k;
    operations += 3;
    for (int i = 0; i < vector.size() - 1; ++i) {
        t = false;
        curr_k = k;
        operations += 6;
        for (int j = 0; j < curr_k - 1; ++j) {
            operations += 3;
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                t = true;
                k = j + 1;
                operations += 12;
            }
            operations += 4;
        }
        if (!t) {
            break;
        }
        ++operations;
    }
    return operations;
}

long long Sorting::insertionSort(std::vector<int> &vector) {
    long long operations = 0;
    for (auto current = 1; current < vector.size(); ++current) {
        operations += 3;
        for (auto j = current; j > 0 && vector[j - 1] > vector[j]; --j) {
            operations += 6;
            std::swap(vector[j], vector[j - 1]);
            operations += 9;
        }
    }
    return operations;
}

long long Sorting::binaryInsertionSort(std::vector<int> &vector) {
    int selected, place_to_insert, j;
    int operations = 3;
    for (auto current = 1; current < vector.size(); ++current) {
        operations += 3;

        selected = vector[current];
        j = current - 1;
        operations += 4;
        // find location where selected should be inserted
        place_to_insert = binarySearch(vector, selected, 0, j, operations);

        // Move all elements after location to create space
        while (j >= place_to_insert) {
            vector[j + 1] = vector[j];
            --j;
            operations += 6;
        }
        vector[j + 1] = selected;
        operations += 4;
    }
    return operations;
}

long long Sorting::countingSort(std::vector<int> &vector) {
    int min = INT_MAX;
    int max = INT_MIN;
    long long operations = 2;
    for (auto value: vector) {
        ++operations;
        if (value < min) {
            min = value;
            ++operations;
        }
        ++operations;
        if (value > max) {
            max = value;
            ++operations;
        }
        ++operations;
    }
    countingSort1(vector, min, max, operations);
    return operations;
}

long long Sorting::digitalSort(std::vector<int> &vector) {
    std::vector<Number> numbers;
    long long operations = 1;
    for (auto value: vector) {
        numbers.emplace_back(Number(value));
        operations += 2;
    }
    for (int i = 0; i < 4; ++i) {
        operations += 2;
        numbers = countingSortForDigitSort(numbers, i, operations);
    }
    for (size_t i = 0; i < vector.size(); ++i) {
        vector[i] = numbers[i].number;
        operations += 7;
    }
    return operations;
}

long long Sorting::mergeSort(std::vector<int> &vector) {
    long long operations = 0;
    mergeSort1(vector.begin(), vector.end(), operations);
    return operations;
}

long long Sorting::quickSort(std::vector<int> &vector) {
    long long operations = 0;
    quickSort1(vector, 0, vector.size() - 1, operations);
    return operations;
}

long long Sorting::heapSort(std::vector<int> &vector) {
    long long operations = 0;
    HeapSorted heap = HeapSorted(vector, operations);
    vector = std::move(heap.getHeap());
    ++operations;
    return operations;
}

long long Sorting::shellSort_Tsiur(std::vector<int> &vector) {
    long long operations = 9;
    std::vector<int> tsiur = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    for (int gap: tsiur) {
        ++operations;
        for (int i = gap; i < vector.size(); ++i) {
            operations += 5;
            for (int j = i - gap; j >= 0 && vector[j] > vector[j + gap]; j -= gap) {
                operations += 6;
                std::swap(vector[j], vector[j + gap]);
                operations += 9;
            }
            operations += 6;
        }
    }
    return operations;
}

long long Sorting::shellSort_Shell(std::vector<int> &vector) {
    size_t first = 0;
    size_t last = vector.size();
    long long operations = 2 + 3;
    for (auto d = (first + last) / 2; d != 0; d /= 2) {
        operations += 4;
        for (auto i = first + d; i != last; ++i) {
            operations += 3;
            for (auto j = i; j - first >= d && vector[j] < vector[j - d]; j -= d) {
                operations += 7;
                std::swap(vector[j], vector[j - d]);
                operations += 9;
            }
            operations += 7;
        }
    }
    return operations;
}

int Sorting::mergeSort1(const std::vector<int>::iterator begin, const std::vector<int>::iterator end,
                        long long &operations) {
    auto size = std::distance(begin, end);
    operations += size;
    if (size < 2) {
        ++operations;
        return 0;
    }
    ++operations;

    auto mid = begin + size / 2;
    operations += 3;
    mergeSort1(begin, mid, operations);
    mergeSort1(mid, end, operations);
    merge(begin, mid, end, operations);
}

void Sorting::merge(std::vector<int>::iterator begin, const std::vector<int>::iterator mid,
                    const std::vector<int>::iterator end, long long &operations) {
    std::vector<int> v;
    auto it_l{begin}, it_r{mid};
    auto it_mid{mid}, it_end{end};
    operations += 4;

    while (it_l != it_mid && it_r != it_end) {
        v.emplace_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
        operations += 7;
    }
    ++operations;
    for (auto i = it_l; i != it_mid; ++i) {
        v.emplace_back(*i);
        operations += 4;
    }
    ++operations;
    for (auto i = it_r; i != it_end; ++i) {
        v.emplace_back(*i);
        operations += 4;
    }
    for (auto num: v) {
        *begin = num;
        ++begin;
        operations += 4;
    }
}

void Sorting::countingSort1(std::vector<int> &vec, int min, int max, long long &operations) {
    int k = max - min + 1;
    std::vector<int> b(k);
    operations += 4;
    for (auto value: vec) {
        ++b[value - min];
        operations += 4;
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
        operations += 8;
    }
    std::vector<int> result(vec.size());
    operations += 2;
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i] - min]] = vec[i];
        operations += 9;
    }
    vec = std::move(result);
    ++operations;
}

std::vector<Number> Sorting::countingSortForDigitSort(const std::vector<Number> &vec, int place, long long &operations,
                                                      int min, int max) {
    int k = max - min + 1;
    std::vector<int> b(k);
    operations += 4;

    for (auto &number: vec) {
        ++b[number.bytes[place]];
        operations += 5;
    }
    // array of partial sums
    for (int i = 1; i < k; ++i) {
        b[i] = b[i - 1] + b[i];
        operations += 8;
    }

    std::vector<Number> result(vec.size());
    ++operations;
    operations += 3;
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[--b[vec[i].bytes[place] - min]] = vec[i];
        operations += 11;
    }
    return result;
}

int Sorting::partition(std::vector<int> &vec, int start, int end, long long &operations) {
    int pivot = vec[start];

    int count = 0;
    operations += 5;
    for (int i = start + 1; i <= end; i++) {
        operations += 2;
        if (vec[i] <= pivot) {
            count++;
            operations += 3;
        }
        operations += 2;
    }

    // Giving pivot element its correct position
    int pivot_index = start + count;
    std::swap(vec[pivot_index], vec[start]);
    operations += 11;

    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    operations += 2;
    while (i < pivot_index && j > pivot_index) {
        operations += 2;
        while (vec[i] <= pivot) {
            operations += 3;
            i++;
        }
        operations += 2;
        while (pivot < vec[j]) {
            j--;
            operations += 3;
        }
        operations += 2;
        if (i < pivot_index && j > pivot_index) {
            std::swap(vec[i++], vec[j--]);
            operations += 11;
        }
        operations += 2;
    }

    return pivot_index;
}

void Sorting::quickSort1(std::vector<int> &vector, int start, int end, long long &operations) {
    // base case
    if (start >= end) {
        ++operations;
        return;
    }
    ++operations;

    // partitioning the array
    int p = partition(vector, start, end, operations);
    ++operations;

    // Sorting the left part
    quickSort1(vector, start, p - 1, operations);

    // Sorting the right part
    quickSort1(vector, p + 1, end, operations);
}

int Sorting::binarySearch(const std::vector<int> &vec, int item,
                          int low, int high, int &operations) {
    if (high <= low) {
        operations += 5;
        return (item > vec[low]) ?
               (low + 1) : low;
    }

    int mid = (low + high) / 2;
    operations += 3;

    if (item == vec[mid]) {
        operations += 3;
        return mid + 1;
    }
    operations += 2;

    if (item > vec[mid]) {
        operations += 3;
        return binarySearch(vec, item,
                            mid + 1, high, operations);
    }
    operations += 3;
    return binarySearch(vec, item, low,
                        mid - 1, operations);
}