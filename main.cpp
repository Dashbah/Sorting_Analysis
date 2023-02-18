#include <iostream>
#include <fstream>
#include <vector>
#include "VectorGenerator.h"
#include "CountTime.h"
#include "Sorting.h"

// iconic arrays to copy arrays to work it of them
std::vector<int> FROM_0_TO_5;
std::vector<int> FROM_0_TO_4000;
std::vector<int> ALMOST_SORTED;
std::vector<int> REVERSED;

std::vector<std::string> SORTING_NAMES = {
        "selectionSort", "bubbleSort", "bubbleSort_Aiverson1",
        "bubbleSortAiverson1And2", "insertion sort", "binaryInsertionSort", "countingSort",
        "digitalSort", "mergeSort", "quickSort", "heapSort", "shellSort_Tsiur",
        "shellSort_Shell"
};

int main() {
    std::ofstream Sorting_CSV_File("sorting.csv");         //Opening file to print info to
    Sorting_CSV_File << "Sorting by Dashbah" << std::endl;          //Headings for file

    FROM_0_TO_5 = VectorGenerator::createRandomFromTo(4100, 0, 6);
    FROM_0_TO_4000 = VectorGenerator::createRandomFromTo(4100, 0, 4001);
    ALMOST_SORTED = VectorGenerator::createAlmostSorted(4100);
    REVERSED = VectorGenerator::createReversed(4100);

    // vector of all 13 sorting
    std::vector<int (*)(std::vector<int>&)> sortings = {
            Sorting::selectionSort, Sorting::bubbleSort, Sorting::bubbleSort_Aiverson1,
            Sorting::bubbleSortAiverson1And2, Sorting::insertionSort,
            Sorting::binaryInsertionSort, Sorting::countingSort, Sorting::digitalSort,
            Sorting::mergeSort, Sorting::quickSort, Sorting::heapSort, Sorting::shellSort_Tsiur,
            Sorting::shellSort_Shell
    };
    // array of iconic arrays
    std::vector<std::vector<int>> arrays = {
            FROM_0_TO_5, FROM_0_TO_4000, ALMOST_SORTED, REVERSED
    };

    // working vector, in which we will copy elements at each sorting
    std::vector<int> new_vec;
    for (size_t sorting_type = 0; sorting_type < sortings.size(); ++sorting_type) {
        Sorting_CSV_File << SORTING_NAMES[sorting_type] << ": \n";
        for (int array_type = 0; array_type < 4; ++array_type) {
            Sorting_CSV_File << array_type + 1 << " array type\n";
            Sorting_CSV_File << "\tSmall data:\n\t";
            for (int i = 50; i <= 300; i += 50) {
                Sorting_CSV_File << i << ",";
                new_vec  = std::vector<int>(arrays[array_type].begin(), arrays[array_type].begin() + i);
                auto time = CountTime::countTime(new_vec, sortings[sorting_type]);
                Sorting_CSV_File << time.ms << ',' << time.operations << '\n';
            }
            Sorting_CSV_File << '\n';
            Sorting_CSV_File << "Big data: \n";
            for (int i = 100; i <= 4100; i += 100) {
                Sorting_CSV_File << i << ',';
                new_vec  = std::vector<int>(arrays[array_type].begin(), arrays[array_type].begin() + i);
                auto time = CountTime::countTime(new_vec, sortings[sorting_type]);
                Sorting_CSV_File << time.ms << ',' << time.operations << '\n';
            }
        }
    }

    Sorting_CSV_File.close();
    return 0;
}
