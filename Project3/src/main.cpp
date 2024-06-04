#include <fstream>
#include "../include/LinearProbingHashTable.hpp"
#include "../include/RobinHoodHashTable.hpp"

int main() {
    std::ofstream outputFile("hash_table_performance.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }

    std::vector<int> testSizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    for (int size : testSizes) {
        LinearProbingHashTable linearHashTable;
        RobinHoodHashTable<int, int> robinHoodHashTable(size * 2); // Double the size for Robin Hood Hashing

        outputFile << "Testing with " << size << " elements, 50 trials each:" << std::endl;

        outputFile << "Linear Probing Hash Table:" << std::endl;
        testPerformance(linearHashTable, size, 50);

        outputFile << "Robin Hood Hashing:" << std::endl;
        testPerformance(robinHoodHashTable, size, 50);
    }

    outputFile.close();
    std::cout << "Performance test results saved to 'hash_table_performance.txt'" << std::endl;
    return 0;
}
