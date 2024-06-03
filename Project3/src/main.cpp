#include <iostream>
#include <chrono>
#include <fstream>
#include "../include/HashTable.hpp"
#include "../include/SeparateChainingHashTable.hpp"
#include "../include/LinearProbingHashTable.hpp"
#include "../include/CuckooHashTable.hpp"
#include <cstdlib> // for rand()

void fillHashTableWithRandomNumbers(HashTable* hashTable, int size) {
    for (int i = 0; i < size; ++i) {
        int randomNumber = rand(); // generate a random number
        hashTable->insert(randomNumber); // insert the random number into the hashtable
    }
}
void testHashTable(HashTable* hashTable) {
    int randomNumber = rand(); // generate a random number

    auto start = std::chrono::high_resolution_clock::now();
    hashTable->insert(randomNumber);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> diff = end-start;
    std::cout << "Time to insert: " << diff.count() << " ns\n";

    start = std::chrono::high_resolution_clock::now();
    hashTable->remove(randomNumber);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout << "Time to remove: " << diff.count() << " ns\n";

    delete hashTable;
}
int main() {
    auto separate = new SeparateChainingHashTable(1001);
    auto linear = new LinearProbingHashTable(1001);
    auto cuckoo = new CuckooHashTable(3001);
    std::cout << "Testing Separate Chaining Hash Table:\n";


    fillHashTableWithRandomNumbers(separate, 1000);
    testHashTable(separate);

    std::cout << "\nTesting Linear Probing Hash Table:\n";
    fillHashTableWithRandomNumbers(linear, 1000);
    testHashTable(linear);

    std::cout << "\nTesting Cuckoo Hash Table:\n";
    fillHashTableWithRandomNumbers(cuckoo, 1000);
    testHashTable(cuckoo);
    return 0;
}

