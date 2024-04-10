//
// Created by rexiv on 18.03.2024.
//

#ifndef SORTING_ALGORITHMS_TABLEGENERATOR_H
#define SORTING_ALGORITHMS_TABLEGENERATOR_H

#include <vector>
#include <cstdlib> // for rand and srand
#include <ctime> // for time
#include <algorithm>
std::vector<int> generateRandomVector(long size) {
    std::srand(std::time(nullptr));
    std::vector<int> vec;
    for(int i = 0; i < size; i++) {
        vec.push_back(std::rand());
    }
    return vec;
}
#endif //SORTING_ALGORITHMS_TABLEGENERATOR_H
