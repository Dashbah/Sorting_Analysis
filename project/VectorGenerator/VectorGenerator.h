//
// Created by Dashbah on 17.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_VECTORGENERATOR_H
#define ALGOSI_KDZ1_SORTINGS_VECTORGENERATOR_H

#include <vector>

class VectorGenerator {
public:
    static std::vector<int> createRandomFromTo(size_t size, int lower_bound, int upper_bound);
    static std::vector<int> createAlmostSorted(size_t size);
    static std::vector<int> createReversed(size_t size);
};


#endif //ALGOSI_KDZ1_SORTINGS_VECTORGENERATOR_H
