//
// Created by Dashbah on 19.02.2023.
//

#include "HeapSorted.h"

HeapSorted::HeapSorted(const std::vector<int> &vec) {
    size_ = static_cast<int>(vec.size());
    buildHeap(vec);
    for (int i = size_ - 1; i >= 0; --i) {
        list_[i] = getMax();
        heapify(0);
    }
}

std::vector<int> &HeapSorted::getHeap() {
    return list_;
}


int HeapSorted::getMax() {
    int res = list_[0];
    list_[0] = list_[size_ - 1];
    --size_;
    return res;
}

void HeapSorted::heapify(int i) {
    int left_child;
    int right_child;
    int largest_child;

    for (;;) {
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
        largest_child = i;

        if (left_child < size_ && list_[left_child] > list_[largest_child]) {
            largest_child = left_child;
        }
        if (right_child < size_ && list_[right_child] > list_[largest_child]) {
            largest_child = right_child;
        }
        if (largest_child == i) {
            break;
        }

        int temp = list_[i];
        list_[i] = list_[largest_child];
        list_[largest_child] = temp;
        i = largest_child;
    }
}

void HeapSorted::buildHeap(const std::vector<int> &vec) {
    list_ = vec;
    for (int i = size_ / 2; i >= 0; --i) {
        heapify(i);
    }
}
