#ifndef SEPARATE_CHAINING_HASH_TABLE_HPP
#define SEPARATE_CHAINING_HASH_TABLE_HPP

#include <vector>
#include <list>
#include <functional>
#include "HashTable.hpp"

template<typename K, typename V>
class SeparateChainingHashTable : public HashTable<K, V>{
public:
    explicit SeparateChainingHashTable(size_t tableSize = 101);
    void insert(const K& key, const V& value) override;
    void remove(const K& key) override;
    V search(const K& key) override;

private:
    struct Entry {
        K key;
        V value;
        Entry(const K& key, const V& value) : key(key), value(value) {}
    };

    std::vector<std::list<Entry>> table;
    size_t tableSize;

    int hashFunction(const K& key) const;
};

template<typename K, typename V>
SeparateChainingHashTable<K, V>::SeparateChainingHashTable(size_t tableSize)
        : table(tableSize), tableSize(tableSize) {}

template<typename K, typename V>
int SeparateChainingHashTable<K, V>::hashFunction(const K& key) const {
    return static_cast<int>(std::hash<K>{}(key) % tableSize);
}

template<typename K, typename V>
void SeparateChainingHashTable<K, V>::insert(const K& key, const V& value) {
    int hashValue = hashFunction(key);
    for (auto& entry : table[hashValue]) {
        if (entry.key == key) {
            entry.value = value;
            return;
        }
    }
    table[hashValue].emplace_back(key, value);
}

template<typename K, typename V>
void SeparateChainingHashTable<K, V>::remove(const K& key) {
    int hashValue = hashFunction(key);
    table[hashValue].remove_if([&](const Entry& entry) { return entry.key == key; });
}

template<typename K, typename V>
V SeparateChainingHashTable<K, V>::search(const K& key) {
    int hashValue = hashFunction(key);
    for (const auto& entry : table[hashValue]) {
        if (entry.key == key) {
            return entry.value;
        }
    }
    throw std::runtime_error("Key not found");
}

#endif // SEPARATE_CHAINING_HASH_TABLE_H
