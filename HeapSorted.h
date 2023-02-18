//
// Created by Dashbah on 19.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_HEAPSORTED_H
#define ALGOSI_KDZ1_SORTINGS_HEAPSORTED_H

#include <vector>

class HeapSorted {
public:
    explicit HeapSorted(const std::vector<int> &vec);

    std::vector<int> &getHeap();

private:
    std::vector<int> list_;
    int size_;

    int getMax();

    void heapify(int i = 0);

    void buildHeap(const std::vector<int> &vec);
};


#endif //ALGOSI_KDZ1_SORTINGS_HEAPSORTED_H
