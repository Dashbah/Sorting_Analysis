//
// Created by Dashbah on 17.02.2023.
//

#include "VectorGenerator.h"

std::vector<int> VectorGenerator::createRandomFromTo(size_t size, int lower_bound, int upper_bound) {
    std::vector<int> result = std::vector<int>(size);
    time_t t;

    srand((unsigned) time(&t));

    for (int i = 0; i < size; ++i) {
        int random_num = rand() % (upper_bound) + lower_bound;
        result[i] = random_num;
    }

    return result;
}

std::vector<int> VectorGenerator::createAlmostSorted(size_t size) {
    std::vector<int> result = std::vector<int>(size);

    for (int i = 0; i < size; ++i) {
        result[i] = i;
    }

    size_t k = size / 20.0;
    for (size_t i = k; i < size; i+= k) {
        std::swap(result[i], result[i - k]);
    }

    return result;
}

/**
 * @return array [1, size]
 */
std::vector<int> VectorGenerator::createReversed(size_t size) {
    std::vector<int> result = std::vector<int>(size);
    if (size == 0) {
        return result;
    }

    for (int i = 1; i <= size; ++i) {
        result[size - i] = i;
    }

    return result;
}
