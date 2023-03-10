#include <iostream>
#include <fstream>
#include <vector>
#include "VectorGenerator/VectorGenerator.h"
#include "CountTime/CountTime.h"
#include "Sorting/Sorting.h"

// iconic arrays to copy arrays to work it of them
std::vector<int> FROM_0_TO_5;
std::vector<int> FROM_0_TO_4000;
std::vector<int> ALMOST_SORTED;
std::vector<int> REVERSED;

std::vector<std::string> SORTING_NAMES = {
        "selectionSort", "bubbleSort", "bubbleSort_Iverson1",
        "bubbleSort_Iverson1And2", "insertion sort", "binaryInsertionSort", "countingSort",
        "digitalSort", "mergeSort", "quickSort", "heapSort", "shellSort_Tsiur",
        "shellSort_Shell"
};
std::vector<std::string> ARRAY_NAMES = {
        "Randomfrom0to5", "Randomfrom0to4100",
        "AlmostSorted", "Reversed"
};

int main() {
    std::ofstream Sorting_CSV_File("sorting.csv");
    Sorting_CSV_File << "Sorting by Dashbah" << std::endl;

    FROM_0_TO_5 = VectorGenerator::createRandomFromTo(4100, 0, 6);
    FROM_0_TO_4000 = VectorGenerator::createRandomFromTo(4100, 0, 4001);
    ALMOST_SORTED = VectorGenerator::createAlmostSorted(4100);
    REVERSED = VectorGenerator::createReversed(4100);

    // vector of all 13 sorting
    std::vector<long long (*)(std::vector<int>&)> sorting = {
            Sorting::selectionSort, Sorting::bubbleSort, Sorting::bubbleSort_Iverson1,
            Sorting::bubbleSort_Iverson1And2, Sorting::insertionSort,
            Sorting::binaryInsertionSort, Sorting::countingSort,
            Sorting::digitalSort, Sorting::mergeSort, Sorting::quickSort,
            Sorting::heapSort, Sorting::shellSort_Tsiur, Sorting::shellSort_Shell
    };
    // array of iconic arrays
    std::vector<std::vector<int>> arrays = {
            FROM_0_TO_5, FROM_0_TO_4000, ALMOST_SORTED, REVERSED
    };

    // working vector, in which we will copy elements at each sorting
    std::vector<int> new_vec;
    for (size_t sorting_type = 0; sorting_type < sorting.size(); ++sorting_type) {
        std::cout << SORTING_NAMES[sorting_type] << "\n";
        Sorting_CSV_File << SORTING_NAMES[sorting_type] << "\n";
        for (int array_type = 0; array_type < 4; ++array_type) {
            Sorting_CSV_File << ARRAY_NAMES[array_type] << "\n";
            Sorting_CSV_File << "\tSmall data:\n\t";
            for (int i = 50; i <= 300; i += 50) {
                Sorting_CSV_File << i << ",";
                new_vec  = std::vector<int>(arrays[array_type].begin(), arrays[array_type].begin() + i);
                long long average_ms = 0, average_operations = 0;
                for (int q = 0; q < 10; ++q) {
                    auto time = CountTime::countTime(new_vec, sorting[sorting_type]);
                    average_ms += time.ms / 10;
                    average_operations += time.operations / 10;
                }
                Sorting_CSV_File << average_ms << ',' << average_operations << '\n';
            }
            Sorting_CSV_File << '\n';
            Sorting_CSV_File << "Big data: \n";
            for (int i = 100; i <= 4100; i += 100) {
                Sorting_CSV_File << i << ',';
                new_vec  = std::vector<int>(arrays[array_type].begin(), arrays[array_type].begin() + i);
                long long average_ms = 0, average_operations = 0;
                for (int q = 0; q < 10; ++q) {
                    auto time = CountTime::countTime(new_vec, sorting[sorting_type]);
                    average_ms += time.ms / 10;
                    average_operations += time.operations / 10;
                }
                Sorting_CSV_File << average_ms << ',' << average_operations << '\n';
            }
        }
    }

    Sorting_CSV_File.close();
    return 0;
}
