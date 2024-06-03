#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "HashTable.hpp"

#include <vector>
#include <list>
#include <functional>
#include "HashTable.hpp"

/**
 * @class SeparateChainingHashTable
 * @brief Implements a hash table using chaining for collision resolution.
 *
 * @tparam K Type of keys stored in the hash table.
 * @tparam V Type of values stored in the hash table.
 */
template<typename K, typename V>
class SeparateChainingHashTable : public HashTable<K, V>{
private:
    struct Entry {
        K key;
        V value;

        Entry(const K& k, const V& v) : key(k), value(v) {}
    };

    std::vector<std::list<Entry>> table;
    static const int TABLE_SIZE = 1000000;

    /**
     * @brief Hash function to map keys to table indices.
     *
     * @param key The key to hash.
     * @return The hashed index.
     */
    int hashFunction(const K& key) const;

public:
    /**
     * @brief Constructs a HashTable with a predefined size.
     */
    SeparateChainingHashTable();

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
     */
    void remove(const K& key) override;

    /**
     * @brief Searches for a value associated with a given key.
     *
     * @param key The key to search for.
     * @param value Output parameter to store the found value.
     * @return true if the key was found, false otherwise.
     */
    bool search(const K& key, V& value) const;
};


#endif // HASH_TABLE_H
