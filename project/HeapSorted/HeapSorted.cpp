//
// Created by Dashbah on 19.02.2023.
//

#include "HeapSorted.h"

HeapSorted::HeapSorted(const std::vector<int> &vec, long long &operations) {
    this->operations = &operations;
    size_ = static_cast<int>(vec.size());
    ++operations;
    buildHeap(vec);
    for (int i = size_ - 1; i >= 0; --i) {
        list_[i] = getMax();
        heapify(0);
        operations += 5;
    }
}

std::vector<int> &HeapSorted::getHeap() {
    return list_;
}


int HeapSorted::getMax() {
    int res = list_[0];
    list_[0] = list_[size_ - 1];
    --size_;
    operations += 7;
    return res;
}

void HeapSorted::heapify(int i) {
    int left_child;
    int right_child;
    int largest_child;
    operations += 3;

    for (;;) {
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
        largest_child = i;
        operations += 7;

        if (left_child < size_ && list_[left_child] > list_[largest_child]) {
            largest_child = left_child;
            ++operations;
        }
        if (right_child < size_ && list_[right_child] > list_[largest_child]) {
            largest_child = right_child;
            ++operations;
        }
        operations += 8;
        if (largest_child == i) {
            ++operations;
            break;
        }
        ++operations;

        int temp = list_[i];
        list_[i] = list_[largest_child];
        list_[largest_child] = temp;
        i = largest_child;
        operations += 8;
    }
}

void HeapSorted::buildHeap(const std::vector<int> &vec) {
    list_ = vec;
    operations += list_.size();
    ++operations;
    for (int i = size_ / 2; i >= 0; --i) {
        operations += 2;
        heapify(i);
    }
}
