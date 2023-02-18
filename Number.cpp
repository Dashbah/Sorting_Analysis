//
// Created by Dashbah on 19.02.2023.
//

#include "Number.h"

Number::Number::Number(int number) : number(number) {
    bytes[0] = (number & 0x000000FF);
    bytes[1] = (number & 0x0000FF00) >> 8;
    bytes[2] = (number & 0x00FF0000) >> 16;
    bytes[3] = (number & 0xFF000000) >> 24;
}