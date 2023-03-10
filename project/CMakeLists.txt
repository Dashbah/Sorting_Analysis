cmake_minimum_required(VERSION 3.23)
project(Algosi_KDZ1_Sortings)

set(CMAKE_CXX_STANDARD 23)

add_executable(Algosi_KDZ1_Sortings main.cpp
        Sorting/Sorting.cpp Sorting/Sorting.h
        VectorGenerator/VectorGenerator.cpp VectorGenerator/VectorGenerator.h
        CountTime/CountTime.cpp CountTime/CountTime.h
        HeapSorted/HeapSorted.cpp HeapSorted/HeapSorted.h
        Number/Number.cpp Number/Number.h)
