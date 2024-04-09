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
    T *arr; // Pointer to the dynamically allocated array
    int capacity; // Capacity of the array
    int size; // Current number of elements in the array

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
            // Free existing memory
            delete[] arr;

            // Copy size and capacity
            size = other.size;
            capacity = other.capacity;

            // Allocate new memory and copy elements
            arr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Function to add an element to the front of the array
    void prepend(const T& element) {
        insert(0, element);
    }

    // Function to add an element to the back of the array
    void append(const T& element) {
        insert(size, element);
    }

    // Function to add an element at a specific index
    void insert(int index, const T& element) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of bounds");
        }
        if (size == capacity) {
            // If the array is full, double its capacity
            capacity *= 2;
            T *tempArr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                tempArr[i] = arr[i];
            }
            delete[] arr;
            arr = tempArr;
        }
        // Shift elements to the right to make space for the new element
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        size++;
    }

    // Function to delete an element from a specific index
    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        // Shift elements to the left to cover the removed element
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Function to check if the array contains a given element
    bool contains(const T& element) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Function to get the element at a specific index
    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    // Function to set the value at a specific index
    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        arr[index] = value;
    }

    // Function to get the current size of the array
    int getSize() const {
        return size;
    }
};



#endif //DATASTRUCTURES_DYNAMICARRAY_H
