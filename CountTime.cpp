//
// Created by Dashbah on 17.02.2023.
//

#include "CountTime.h"
#include <chrono>

Time CountTime::countTime(std::vector<int> vector, int (*func)(std::vector<int> &)) {
    auto t1 = std::chrono::high_resolution_clock::now();
    long long operations = func(vector);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto total_result = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    return Time{total_result / 100, operations};
}
