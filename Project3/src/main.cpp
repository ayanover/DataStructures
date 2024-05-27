#include <iostream>
#include "../include/HashTable.hpp"
#include "../include/SeparateChainingHashTable.hpp"
#include "../include/LinearProbingHashTable.hpp"
#include "../include/CuckooHashTable.hpp"

void testHashTable(HashTable* hashTable) {
    hashTable->insert(15);
    hashTable->insert(10);
    hashTable->insert(13);
    hashTable->insert(14);
    hashTable->insert(25);
    hashTable->insert(35);

    std::cout << "After insertions:\n";
    hashTable->display();

    hashTable->remove(25);
    std::cout << "\nAfter removal of 25:\n";
    hashTable->display();

    hashTable->remove(15);
    std::cout << "\nAfter removal of 15:\n";
    hashTable->display();

    delete hashTable;
}

int main() {
    std::cout << "Testing Separate Chaining Hash Table:\n";
    testHashTable(new SeparateChainingHashTable(10));

    std::cout << "\nTesting Linear Probing Hash Table:\n";
    testHashTable(new LinearProbingHashTable(10));

    std::cout << "\nTesting Cuckoo Hash Table:\n";
    testHashTable(new CuckooHashTable(10));

    return 0;
}

