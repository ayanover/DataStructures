#ifndef LINEAR_PROBING_HASH_TABLE_HPP
#define LINEAR_PROBING_HASH_TABLE_HPP

#include <vector>
#include <functional>
#include <limits>
#include <iostream>
#include "HashTable.hpp"

template<typename K, typename V>
class LinearProbingHashTable : public HashTable<K, V>{
public:
    explicit LinearProbingHashTable(size_t tableSize = 1000001);
    void insert(const K& key, const V& value) override;
    void remove(const K& key) override;
    V search(const K& key) override;

private:
    struct Entry {
        K key;
        V value;
        bool isOccupied = false;
    };

    std::vector<Entry> table;
    size_t tableSize;
    static const K EMPTY_SLOT;

    int hashFunction(const K& key) const;
};

template<typename K, typename V>
const K LinearProbingHashTable<K, V>::EMPTY_SLOT = std::numeric_limits<K>::min();

template<typename K, typename V>
LinearProbingHashTable<K, V>::LinearProbingHashTable(size_t tableSize)
        : table(tableSize), tableSize(tableSize) {
    for (auto& entry : table) {
        entry.key = EMPTY_SLOT;
    }
}

template<typename K, typename V>
int LinearProbingHashTable<K, V>::hashFunction(const K& key) const {
    return static_cast<int>(std::hash<K>{}(key) % tableSize);
}

template<typename K, typename V>
void LinearProbingHashTable<K, V>::insert(const K& key, const V& value) {
    int hashValue = hashFunction(key);
    int startValue = hashValue;
    while (table[hashValue].isOccupied) {
        if (table[hashValue].key == key) {
            table[hashValue].value = value;
            return;
        }
        hashValue = (hashValue + 1) % tableSize;
        if (hashValue == startValue) {
            std::cerr << "HashTable is full. Cannot insert key: " << key << std::endl;
            return;
        }
    }
    table[hashValue].key = key;
    table[hashValue].value = value;
    table[hashValue].isOccupied = true;
}

template<typename K, typename V>
void LinearProbingHashTable<K, V>::remove(const K& key) {
    int hashValue = hashFunction(key);
    int startValue = hashValue;
    while (table[hashValue].isOccupied) {
        if (table[hashValue].key == key) {
            table[hashValue].isOccupied = false;
            table[hashValue].key = EMPTY_SLOT;
            return;
        }
        hashValue = (hashValue + 1) % tableSize;
        if (hashValue == startValue) {
            return;
        }
    }
    return;
}

template<typename K, typename V>
V LinearProbingHashTable<K, V>::search(const K& key) {
    int hashValue = hashFunction(key);
    int startValue = hashValue;
    while (table[hashValue].isOccupied) {
        if (table[hashValue].key == key) {
            return table[hashValue].value;
        }
        hashValue = (hashValue + 1) % tableSize;
        if (hashValue == startValue) {
            break;
        }
    }
    throw std::runtime_error("Key not found");
}

#endif // LINEAR_PROBING_HASH_TABLE_HPP
