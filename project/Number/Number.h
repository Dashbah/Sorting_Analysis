//
// Created by Dashbah on 19.02.2023.
//

#ifndef ALGOSI_KDZ1_SORTINGS_NUMBER_H
#define ALGOSI_KDZ1_SORTINGS_NUMBER_H


struct Number {
    int number;
    unsigned char bytes[4];

    Number() = default;

    Number(int number);
};


#endif //ALGOSI_KDZ1_SORTINGS_NUMBER_H
