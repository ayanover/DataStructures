#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class CuckooHashTable : public HashTable{
private:
    int tablesize;
    vector<vector<int>> table;

    size_t hash(int key, size_t index) {
        if (index == 0) {
            return key % tablesize;
        } else {
            return (key / tablesize) % tablesize;
        }
    }

public:
    CuckooHashTable(int size) : tablesize(size), table(size, vector<int>(2, -1)) {}

    void insert(int key) override{
        bool placed = false;
        size_t pos;
        int index = 0;
        int temp_key = key;
        int counter = 0;

        while (!placed && counter < 2 * tablesize) {
            pos = hash(temp_key, index);

            if (table[pos][index] == -1) {
                table[pos][index] = temp_key;
                placed = true;
                return;
            } else {
                swap(table[pos][index], temp_key);
                index = 1 - index;
                counter++;
            }
        }
        return;
    }

    void remove(int key) override{
        for (int index = 0; index < 2; ++index) {
            size_t pos = hash(key, index);
            if (table[pos][index] == key) {
                table[pos][index] = -1;
                return ;
            }
        }
        return;
    }

    void display() {
        for (int i = 0; i < tablesize; ++i) {
            cout << "table[" << i << "][0]: " << (table[i][0] == -1 ? "empty" : to_string(table[i][0])) << " ";
            cout << "table[" << i << "][1]: " << (table[i][1] == -1 ? "empty" : to_string(table[i][1])) << endl;
        }
    }
};