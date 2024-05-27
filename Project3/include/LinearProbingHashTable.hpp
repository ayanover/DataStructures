//
// Created by rexiv on 26.05.2024.
//

#ifndef DATASTRUCTURES_LINEARPROBINGHASHTABLE_HPP
#define DATASTRUCTURES_LINEARPROBINGHASHTABLE_HPP


#include <iostream>
#include <vector>
#include "HashTable.hpp"

class LinearProbingHashTable : public HashTable{
private:
    int capacity;
    std::vector<int> table;
    std::vector<bool> occupied;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    LinearProbingHashTable(int size) : capacity(size), table(size, -1), occupied(size, false) {}

    void insert(int key) override{
        int index = hashFunction(key);
        while (occupied[index]) {
            index = (index + 1) % capacity;
        }
        table[index] = key;
        occupied[index] = true;
    }

    void remove(int key) override{
        int index = hashFunction(key);
        while (occupied[index] && table[index] != key) {
            index = (index + 1) % capacity;
        }
        if (table[index] == key) {
            table[index] = -1;
            occupied[index] = false;
        }
    }

    void display() override{
        for (int i = 0; i < capacity; i++) {
            if (occupied[i])
                std::cout << i << ": " << table[i] << std::endl;
            else
                std::cout << i << ": " << "NULL" << std::endl;
        }
    }
};

#endif //DATASTRUCTURES_LINEARPROBINGHASHTABLE_HPP
