//
// Created by rexiv on 26.05.2024.
//

#ifndef DATASTRUCTURES_SEPARATECHAININGHASHTABLE_HPP
#define DATASTRUCTURES_SEPARATECHAININGHASHTABLE_HPP


#include <iostream>
#include <list>
#include <vector>
#include "HashTable.hpp"

class SeparateChainingHashTable : public HashTable {
private:
    int capacity;
    std::vector<std::list<int>> table;

    int hashFunction(int key) const {
        return key % capacity;
    }

public:
    SeparateChainingHashTable(int size) : capacity(size) {
        table.resize(capacity);
    }

    void insert(int key) override {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) override {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void display() override {
        for (int i = 0; i < capacity; i++) {
            std::cout << "Bucket " << i << ": ";
            for (auto& key : table[i]) {
                std::cout << key << " -> ";
            }
            std::cout << "NULL\n";
        }
    }
};
#endif //DATASTRUCTURES_SEPARATECHAININGHASHTABLE_HPP
