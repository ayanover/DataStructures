#include "../../include/RobinHoodHashTable.hpp"

template<typename K, typename V>
void RobinHoodHashTable<K, V>::insert(const K& key, const V& value) {
    int index = hashFunction(key);
    int probe_count = 0;
    Bucket new_bucket(key, value, probe_count);

    while (true) {
        if (table[index].probe_count < new_bucket.probe_count) {
            std::swap(new_bucket, table[index]);
            if (table[index].probe_count == 0) {
                return;
            }
        }
        new_bucket.probe_count++;
        index = (index + 1) % capacity;
    }
}

template<typename K, typename V>
V RobinHoodHashTable<K, V>::search(const K& key) {
    int index = hashFunction(key);
    int probe_count = 0;

    while (probe_count <= table[index].probe_count) {
        if (table[index].key == key) {
            return {table[index].value};
        }
        index = (index + 1) % capacity;
        probe_count++;
    }
    return {};
}

template<typename K, typename V>
void RobinHoodHashTable<K, V>::remove(const K& key) {
    int index = hashFunction(key);
    int probe_count = 0;

    while (probe_count <= table[index].probe_count) {
        if (table[index].key == key) {
            table[index].key = -1;
            return;
        }
        index = (index + 1) % capacity;
        probe_count++;
    }
}
