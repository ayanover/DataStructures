#include "../../include/LinearProbingHashTable.hpp"

template<typename K, typename V>
const K LinearProbingHashTable<K, V>::EMPTY_SLOT = std::numeric_limits<K>::min();

template<typename K, typename V>
void LinearProbingHashTable<K, V>::insert(const K& key, const V& value) {
    int hashValue = hashFunction(key);
    int startValue = hashValue;
    while (table[hashValue].isOccupied) {
        if (table[hashValue].key == key) {
            table[hashValue].value = value;
            return;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
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
bool LinearProbingHashTable<K, V>::remove(const K& key) {
    int hashValue = hashFunction(key);
    int startValue = hashValue;
    while (table[hashValue].isOccupied) {
        if (table[hashValue].key == key) {
            table[hashValue].isOccupied = false;
            return true;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
        if (hashValue == startValue) {
            return false;
        }
    }
    return false;
}

template<typename K, typename V>
bool LinearProbingHashTable<K, V>::search(const K& key, V& value) const {
    int hashValue = hashFunction(key);
    int startValue = hashValue;
    while (table[hashValue].isOccupied) {
        if (table[hashValue].key == key) {
            value = table[hashValue].value;
            return true;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
        if (hashValue == startValue) {
            return false;
        }
    }
    return false;
}
