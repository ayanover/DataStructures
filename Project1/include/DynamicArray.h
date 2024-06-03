//
// Created by rexiv on 13.03.2024.
//

#ifndef DATASTRUCTURES_DYNAMICARRAY_H
#define DATASTRUCTURES_DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>

#include <iostream>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T *arr;
    int capacity;
    int size;

public:
    // Constructor
    DynamicArray(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        arr = new T[capacity];
    }

    // Copy constructor
    DynamicArray(const DynamicArray &other) : capacity(other.capacity), size(other.size) {
        arr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // Assignment operator
    DynamicArray& operator=(const DynamicArray &other) {
        if (this != &other) {
            delete[] arr;

            size = other.size;
            capacity = other.capacity;

            arr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void prepend(const T& element) {
        insert(0, element);
    }

    void append(const T& element) {
        insert(size, element);
    }

    void insert(int index, const T& element) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (size == capacity) {
            capacity *= 2;
            T *tempArr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                tempArr[i] = arr[i];
            }
            delete[] arr;
            arr = tempArr;
        }
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    bool contains(const T& element) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        arr[index] = value;
    }

    int getSize() const {
        return size;
    }
};



#endif //DATASTRUCTURES_DYNAMICARRAY_H
