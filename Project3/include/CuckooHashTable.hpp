//
// Created by rexiv on 26.05.2024.
//

#ifndef DATASTRUCTURES_CUCKOOHASHTABLE_HPP
#define DATASTRUCTURES_CUCKOOHASHTABLE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include "HashTable.hpp"

class CuckooHashTable : public HashTable{
private:
    int capacity;
    std::vector<int> table1;
    std::vector<int> table2;
    std::vector<bool> occupied1;
    std::vector<bool> occupied2;

    int hashFunction1(int key) {
        return key % capacity;
    }

    int hashFunction2(int key) {
        return (key / capacity) % capacity;
    }

    void rehash() {
        std::vector<int> oldTable1 = table1;
        std::vector<int> oldTable2 = table2;
        std::vector<bool> oldOccupied1 = occupied1;
        std::vector<bool> oldOccupied2 = occupied2;

        capacity *= 2;
        table1.assign(capacity, -1);
        table2.assign(capacity, -1);
        occupied1.assign(capacity, false);
        occupied2.assign(capacity, false);

        for (int i = 0; i < oldTable1.size(); ++i) {
            if (oldOccupied1[i]) {
                insert(oldTable1[i]);
            }
        }

        for (int i = 0; i < oldTable2.size(); ++i) {
            if (oldOccupied2[i]) {
                insert(oldTable2[i]);
            }
        }
    }

public:
    CuckooHashTable(int size) : capacity(size), table1(size, -1), table2(size, -1), occupied1(size, false), occupied2(size, false) {}

    void insert(int key) override{
        int count = 0;
        int hash1, hash2;
        while (count < capacity) {
            hash1 = hashFunction1(key);
            if (!occupied1[hash1]) {
                table1[hash1] = key;
                occupied1[hash1] = true;
                return;
            } else {
                std::swap(key, table1[hash1]);
                hash2 = hashFunction2(key);
                if (!occupied2[hash2]) {
                    table2[hash2] = key;
                    occupied2[hash2] = true;
                    return;
                } else {
                    std::swap(key, table2[hash2]);
                }
            }
            count++;
        }
        rehash();
        insert(key);
    }

    void remove(int key) override{
        int hash1 = hashFunction1(key);
        if (occupied1[hash1] && table1[hash1] == key) {
            table1[hash1] = -1;
            occupied1[hash1] = false;
            return;
        }
        int hash2 = hashFunction2(key);
        if (occupied2[hash2] && table2[hash2] == key) {
            table2[hash2] = -1;
            occupied2[hash2] = false;
            return;
        }
    }

    void display() override{
        std::cout << "Table 1:\n";
        for (int i = 0; i < capacity; i++) {
            if (occupied1[i])
                std::cout << i << ": " << table1[i] << std::endl;
            else
                std::cout << i << ": " << "NULL" << std::endl;
        }

        std::cout << "Table 2:\n";
        for (int i = 0; i < capacity; i++) {
            if (occupied2[i])
                std::cout << i << ": " << table2[i] << std::endl;
            else
                std::cout << i << ": " << "NULL" << std::endl;
        }
    }
};

#endif //DATASTRUCTURES_CUCKOOHASHTABLE_HPP
