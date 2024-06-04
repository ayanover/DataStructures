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

template<typename K, typename V>
void testTables(HashTable<K, V>& hashTable, int numberOfElements, int numTrials) {
    std::vector<long long> insertionTimes(numTrials), searchTimes(numTrials), deletionTimes(numTrials);

    for (int trial = 0; trial < numTrials; ++trial) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 1000000000);

        std::vector<std::pair<K, V>> elements(numberOfElements);
        for (auto& element : elements) {
            element = std::make_pair(dis(gen), dis(gen));
        }

        auto start = std::chrono::high_resolution_clock::now();
        for (const auto& [key, value] : elements) {
            hashTable.insert(key, value);
        }
        auto end = std::chrono::high_resolution_clock::now();
        insertionTimes[trial] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numberOfElements; ++i) {
            int randomKey = elements[dis(gen) % numberOfElements].first;
            hashTable.search(randomKey);
        }
        end = std::chrono::high_resolution_clock::now();
        searchTimes[trial] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < numberOfElements; ++i) {
            int randomKey = elements[dis(gen) % numberOfElements].first;
            hashTable.remove(randomKey);
        }
        end = std::chrono::high_resolution_clock::now();
        deletionTimes[trial] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

    double avgInsertionTime = std::accumulate(insertionTimes.begin(), insertionTimes.end(), 0.0) / numTrials;
    double avgSearchTime = std::accumulate(searchTimes.begin(), searchTimes.end(), 0.0) / numTrials;
    double avgDeletionTime = std::accumulate(deletionTimes.begin(), deletionTimes.end(), 0.0) / numTrials;

    std::cout << "Average insertion time for " << numberOfElements << " elements: " << avgInsertionTime << " ms\n";
    std::cout << "Average deletion time for " << numberOfElements << " elements: " << avgDeletionTime << " ms\n" << std::endl;
}

#endif // HASH_TABLE_H
