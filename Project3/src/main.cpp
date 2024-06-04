#include <fstream>
#include "../include/LinearProbingHashTable.hpp"
#include "../include/RobinHoodHashTable.hpp"
#include "../include/SeparateChainingHashTable.hpp"
#include "../include/HashTable.hpp"

int main() {
    std::ofstream outputFile("hash_table_performance.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file!" << '\n';
        return 1;
    }

    std::vector<int> testSizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    for (int size : testSizes) {
        SeparateChainingHashTable<int, int> separateHashTable(size);
        LinearProbingHashTable<int, int> linearHashTable(size * 2);
        RobinHoodHashTable<int, int> robinHoodHashTable(size * 2);

        outputFile << "Testing with " << size << " elements, 50 trials each:" << '\n';

        outputFile << "Separate Chaining Hash Table:" << '\n';
        separateHashTable.testTable( size, 3);

        outputFile << "Linear Probing Hash Table:" << '\n';
        separateHashTable.testTable( size, 3);

        outputFile << "Robin Hood Hashing:" << '\n';
        separateHashTable.testTable( size, 3);
    }

    outputFile.close();
    std::cout << "Performance test results saved to 'hash_table_performance.txt'" << std::endl;
    return 0;
}
