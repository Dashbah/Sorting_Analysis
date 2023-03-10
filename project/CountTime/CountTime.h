//
// Created by Dashbah on 17.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_COUNTTIME_H
#define ALGOSI_KDZ1_SORTINGS_COUNTTIME_H

#include <vector>

struct Time{
    long long ms;
    long long operations;
};

class CountTime {
public:
    static Time countTime(std::vector<int> vector, long long (*func)(std::vector<int>&));
};


#endif //ALGOSI_KDZ1_SORTINGS_COUNTTIME_H
