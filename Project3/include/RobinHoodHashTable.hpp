#ifndef ROBIN_HOOD_HASHING_HPP
#define ROBIN_HOOD_HASHING_HPP

#include <vector>
#include <chrono>
#include <random>
#include <numeric>
#include "HashTable.hpp"

/**
 * @class RobinHoodHashing
 * @brief Implements a hash table using Robin Hood hashing technique.
 *
 * @tparam K Type of keys stored in the hash table.
 * @tparam V Type of values stored in the hash table.
 */
template<typename K, typename V>
class RobinHoodHashTable : public HashTable<K, V>{
private:
    struct Bucket {
        K key;
        V value;
        int probe_count;

        Bucket() : probe_count(0) {}
        Bucket(const K& k, const V& v, int p) : key(k), value(v), probe_count(p) {}
    };

    std::vector<Bucket> table;
    int capacity;

    int hashFunction(const K& key) {
        return key % capacity;
    }

public:
    /**
     * @brief Constructs a RobinHoodHashing object with a specified capacity.
     *
     * @param size The capacity of the hash table.
     */
    RobinHoodHashTable(int size) : capacity(size), table(size) {}

    /**
     * @brief Inserts a key-value pair into the hash table.
     *
     * @param key The key to insert.
     * @param value The value associated with the key.
     */
    void insert(const K& key, const V& value) override;

    /**
     * @brief Searches for a key in the hash table and returns its associated value, if found.
     *
     * @param key The key to search for.
     * @return An optional containing the value associated with the key, or an empty optional if the key is not found.
     */
    V search(const K& key) override;

    /**
     * @brief Removes a key and its associated value from the hash table.
     *
     * @param key The key to remove.
     */
    void remove(const K& key) override;
};


#endif // ROBIN_HOOD_HASHING_H
