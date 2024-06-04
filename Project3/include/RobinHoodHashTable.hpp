#ifndef ROBIN_HOOD_HASHING_HPP
#define ROBIN_HOOD_HASHING_HPP

#include <vector>
#include <stdexcept>
#include "HashTable.hpp"

template<typename K, typename V>
class RobinHoodHashTable : public HashTable<K, V> {
public:
    explicit RobinHoodHashTable(int size) : capacity(size), table(size), EMPTY_KEY(-1), DELETED_KEY(-2) {
        for (auto &bucket : table) {
            bucket.key = EMPTY_KEY;
        }
    }

    void insert(const K& key, const V& value) override;
    V search(const K& key) override;
    void remove(const K& key) override;

private:
    struct Bucket {
        K key;
        V value;
        int probe_count;

        Bucket() : key(-1), probe_count(0) {}
        Bucket(const K& k, const V& v, int p) : key(k), value(v), probe_count(p) {}
    };

    std::vector<Bucket> table;
    int capacity;
    const K EMPTY_KEY;
    const K DELETED_KEY;

    int hashFunction(const K& key) const {
        return key % capacity;
    }

    void resizeTable();
};

template<typename K, typename V>
void RobinHoodHashTable<K, V>::insert(const K& key, const V& value) {
    int index = hashFunction(key);
    int probe_count = 0;
    Bucket new_bucket(key, value, probe_count);

    while (true) {
        if (table[index].key == EMPTY_KEY || table[index].key == DELETED_KEY || table[index].probe_count < new_bucket.probe_count) {
            if (table[index].key == EMPTY_KEY || table[index].key == DELETED_KEY) {
                table[index] = new_bucket;
                return;
            }
            std::swap(new_bucket, table[index]);
        }
        new_bucket.probe_count++;
        index = (index + 1) % capacity;

        // If we loop around, resize the table
        if (index == hashFunction(key)) {
            resizeTable();
            insert(key, value);
            return;
        }
    }
}

template<typename K, typename V>
V RobinHoodHashTable<K, V>::search(const K& key) {
    int index = hashFunction(key);
    int probe_count = 0;

    while (probe_count <= table[index].probe_count) {
        if (table[index].key == key) {
            return table[index].value;
        }
        if (table[index].key == EMPTY_KEY) {
            break;
        }
        index = (index + 1) % capacity;
        probe_count++;
    }
    throw std::runtime_error("Key not found");
}

template<typename K, typename V>
void RobinHoodHashTable<K, V>::remove(const K& key) {
    int index = hashFunction(key);
    int probe_count = 0;

    while (probe_count <= table[index].probe_count) {
        if (table[index].key == key) {
            table[index].key = DELETED_KEY;
            table[index].value = V();
            return;
        }
        if (table[index].key == EMPTY_KEY) {
            return;
        }
        index = (index + 1) % capacity;
        probe_count++;
    }
}

template<typename K, typename V>
void RobinHoodHashTable<K, V>::resizeTable() {
    std::vector<Bucket> old_table = table;
    capacity *= 2;
    table = std::vector<Bucket>(capacity);
    for (auto &bucket : table) {
        bucket.key = EMPTY_KEY;
    }

    for (const auto& bucket : old_table) {
        if (bucket.key != EMPTY_KEY && bucket.key != DELETED_KEY) {
            insert(bucket.key, bucket.value);
        }
    }
}

#endif // ROBIN_HOOD_HASHING_HPP
