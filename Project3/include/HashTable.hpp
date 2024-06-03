#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <numeric>
#include <optional>

template<typename K, typename V>
class HashTable {
public:
    virtual void insert(const K& key, const V& value) = 0;
    virtual V search(const K& key) = 0;
    virtual void remove(const K& key) = 0;
};


#endif // HASH_TABLE_H
