//
// Created by rexiv on 13.03.2024.
//

#ifndef DATASTRUCTURES_SINGLYLINKEDLIST_H
#define DATASTRUCTURES_SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr), size(0) {
        Node* current = other.head;
        while (current != nullptr) {
            append(current->data);
            current = current->next;
        }
    }

    ~SinglyLinkedList() {
        clear();
    }

    void prepend(const T& val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void append(const T& val) {
        if (head == nullptr) {
            prepend(val);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(val);
        size++;
    }

    void insert(int index, const T& val) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            prepend(val);
            return;
        }
        if (index == size) {
            append(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    bool contains(const T& val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void set(int index, const T& val) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = val;
    }

    int getSize() {
        return size;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }
};



#endif //DATASTRUCTURES_SINGLYLINKEDLIST_H
