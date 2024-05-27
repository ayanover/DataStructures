//
// Created by rexiv on 26.05.2024.
//

#ifndef DATASTRUCTURES_HASHTABLE_HPP
#define DATASTRUCTURES_HASHTABLE_HPP

class HashTable {
public:
    virtual void insert(int key) = 0;
    virtual void remove(int key) = 0;
    virtual void display() = 0;
    virtual ~HashTable() = default;
};

#endif //DATASTRUCTURES_HASHTABLE_HPP
