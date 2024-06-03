#ifndef LINEAR_PROBING_HASH_TABLE_HPP
#define LINEAR_PROBING_HASH_TABLE_HPP

#include <vector>
#include <functional>
#include <limits>
#include <iostream>
#include "HashTable.hpp"

/**
 * @class LinearProbingHashTable
 * @brief Implements a hash table with linear probing for collision resolution.
 *
 * @tparam K Type of keys stored in the hash table.
 * @tparam V Type of values stored in the hash table.
 */
template<typename K, typename V>
class LinearProbingHashTable : public HashTable<K, V>{
private:
    /**
     * @struct Entry
     * @brief Represents an entry in the hash table.
     */
    struct Entry {
        K key;
        V value;
        bool isOccupied;

        Entry() : key{}, value{}, isOccupied(false) {}
    };

    std::vector<Entry> table;
    static const int TABLE_SIZE = 100000000;
    static const K EMPTY_SLOT;

    /**
     * @brief Hash function to map keys to table indices.
     *
     * @param key The key to hash.
     * @return The hashed index.
     */
    int hashFunction(const K& key) const {
        return static_cast<int>(std::hash<K>{}(key) % TABLE_SIZE);
    }

public:
    /**
     * @brief Constructs a LinearProbingHashTable with a predefined size.
     */
    LinearProbingHashTable() : table(TABLE_SIZE) {}

    /**
     * @brief Inserts a key-value pair into the hash table.
     *
     * @param key The key to insert.
     * @param value The value associated with the key.
     */
    void insert(const K& key, const V& value) override;

    /**
     * @brief Removes a key-value pair from the hash table.
     *
     * @param key The key to remove.
     * @return true if the key was found and removed, false otherwise.
     */
    bool remove(const K& key) override;

    /**
     * @brief Searches for a value associated with a given key.
     *
     * @param key The key to search for.
     * @param value Output parameter to store the found value.
     * @return true if the key was found, false otherwise.
     */
    bool search(const K& key, V& value) const override;
};

#endif // LINEAR_PROBING_HASH_TABLE_HPP
