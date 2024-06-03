#include "../../include/SeparateChainingHashTable.hpp"

template<typename K, typename V>
const int SeparateChainingHashTable<K, V>::TABLE_SIZE;

template<typename K, typename V>
SeparateChainingHashTable<K, V>::SeparateChainingHashTable() : table(TABLE_SIZE) {}

template<typename K, typename V>
int SeparateChainingHashTable<K, V>::hashFunction(const K& key) const {
    return static_cast<int>(std::hash<K>{}(key) % TABLE_SIZE);
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
bool SeparateChainingHashTable<K, V>::search(const K& key, V& value) const {
    int hashValue = hashFunction(key);
    for (const auto& entry : table[hashValue]) {
        if (entry.key == key) {
            value = entry.value;
            return true;
        }
    }
    return false;
}
